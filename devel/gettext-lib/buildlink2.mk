# $NetBSD: buildlink2.mk,v 1.10 2002/11/26 10:25:05 jlam Exp $

.if !defined(GETTEXT_BUILDLINK2_MK)
GETTEXT_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.gettext?=	gettext-lib>=0.10.35nb1
BUILDLINK_PKGSRCDIR.gettext?=	../../devel/gettext-lib

.if defined(USE_GNU_GETTEXT)
_NEED_GNU_GETTEXT=	YES
.else
_BLNK_LIBINTL_LIST!=	${ECHO} /usr/lib/libintl.*
.  if ${_BLNK_LIBINTL_LIST} != "/usr/lib/libintl.*"
_BLNK_LIBINTL_FOUND=	YES
.  else
_BLNK_LIBINTL_FOUND=	NO
.  endif
.  if exists(/usr/include/libintl.h)
#
# Consider the base system libintl to be gettext-lib-0.10.35nb1.
#
_GETTEXT_PKG=		gettext-lib-0.10.35nb1
_GETTEXT_DEPENDS=	${BUILDLINK_DEPENDS.gettext}
_NEED_GNU_GETTEXT!= \
	if ${PKG_ADMIN} pmatch '${_GETTEXT_DEPENDS}' ${_GETTEXT_PKG}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  else
_NEED_GNU_GETTEXT=	YES
.  endif
#
# Solaris has broken (for the purposes of pkgsrc) version of zlib and
# gettext.
#
_INCOMPAT_GETTEXT=	SunOS-*-*
INCOMPAT_GETTEXT?=	# empty
.  for _pattern_ in ${_INCOMPAT_GETTEXT} ${INCOMPAT_GETTEXT}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_GNU_GETTEXT=	YES
.    endif
.  endfor
.endif

.if ${_NEED_GNU_GETTEXT} == "YES"
BUILDLINK_PACKAGES+=			gettext
EVAL_PREFIX+=	BUILDLINK_PREFIX.gettext=gettext-lib
BUILDLINK_PREFIX.gettext_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.gettext=	/usr
.endif

BUILDLINK_FILES.gettext=	include/libintl.h
BUILDLINK_FILES.gettext+=	lib/libintl.*

BUILDLINK_TARGETS+=		gettext-buildlink
.if ${_BLNK_LIBINTL_FOUND} == "YES"
BUILDLINK_TARGETS+=		gettext-libintl-la
.endif

# Add -lintl to LIBS in CONFIGURE_ENV to work around broken gettext.m4:
# older gettext.m4 does not add -lintl where it should, and the resulting
# configure script fails to detect if libintl.a is the genuine GNU gettext
# or not.
#
_BLNK_INCINTL=		# empty
_BLNK_LIBINTL=		# empty
.if ${_NEED_GNU_GETTEXT} == "YES"
_BLNK_INCINTL+=		-I${BUILDLINK_PREFIX.gettext}/include
_BLNK_LIBINTL+=		-L${BUILDLINK_PREFIX.gettext}/lib
_BLNK_LIBINTL+=		-Wl,-R${BUILDLINK_PREFIX.gettext}/lib
_BLNK_LIBINTL+=		-lintl
.else
.  if ${_BLNK_LIBINTL_FOUND} == "YES"
_BLNK_LIBINTL+=		-lintl
.  endif
.endif

.if defined(GNU_CONFIGURE)
LIBS+=			${_BLNK_LIBINTL}
CONFIGURE_ENV+=		INTLLIBS="${_BLNK_LIBINTL}"
.  if ${_NEED_GNU_GETTEXT} == "NO"
#CONFIGURE_ENV+=	INCINTL="${_BLNK_INCINTL}"
#CONFIGURE_ENV+=	LIBINTL="${_BLNK_LIBINTL}"
#CONFIGURE_ENV+=	gt_cv_func_gnugettext_libintl="yes"
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl="yes"
.  endif
.endif

.if ${_NEED_GNU_GETTEXT} == "NO"
.  if ${_BLNK_LIBINTL_FOUND} == "YES"
_BLNK_INTL_LDFLAGS=	-L${BUILDLINK_PREFIX.gettext}/lib -lintl
.  else
_BLNK_INTL_LDFLAGS=	# empty
.  endif
LIBTOOL_ARCHIVE_UNTRANSFORM_SED+= \
	-e "s|${BUILDLINK_PREFIX.gettext}/lib/libintl.la|${_BLNK_INTL_LDFLAGS}|g" \
	-e "s|${LOCALBASE}/lib/libintl.la|${_BLNK_INTL_LDFLAGS}|g"
.endif

gettext-buildlink: _BUILDLINK_USE

gettext-libintl-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libintl.la";			\
	libpattern="${BUILDLINK_PREFIX.gettext}/lib/libintl.*";		\
	${BUILDLINK_FAKE_LA}

.endif	# GETTEXT_BUILDLINK2_MK
