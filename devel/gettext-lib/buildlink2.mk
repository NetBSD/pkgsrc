# $NetBSD: buildlink2.mk,v 1.3 2002/09/18 01:05:45 jlam Exp $

.if !defined(GETTEXT_BUILDLINK2_MK)
GETTEXT_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.gettext?=	gettext-lib>=0.10.35nb1
BUILDLINK_PKGSRCDIR.gettext?=	../../devel/gettext-lib

.if defined(USE_GNU_GETTEXT)
_NEED_GNU_GETTEXT=	YES
.else
.  if exists(/usr/include/libintl.h)
_NEED_GNU_GETTEXT=	NO
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
BUILDLINK_TARGETS+=		gettext-libintl-la

# Add -lintl to LIBS in CONFIGURE_ENV to work around broken gettext.m4:
# gettext.m4 does not add -lintl where it should, and the resulting
# configure script fails to detect if libintl.a is the genuine GNU gettext
# or not.
#
_BLNK_INTLLIBS=		# empty
.if ${_NEED_GNU_GETTEXT} == "YES"
_BLNK_INTLLIBS+=	-L${BUILDLINK_DIR}/lib
.  if ${_USE_RPATH} == "yes"
_BLNK_INTLLIBS+=	-Wl,-R${BUILDLINK_PREFIX.gettext}/lib
.  endif
.endif
_BLNK_INTLLIBS+=	-lintl
.if defined(GNU_CONFIGURE)
INTLLIBS=		${_BLNK_INTLLIBS}
LIBS+=			${INTLLIBS}
CONFIGURE_ENV+=		INTLLIBS="${INTLLIBS}"
.endif

.if ${_NEED_GNU_GETTEXT} == "NO"
LIBTOOL_ARCHIVE_UNTRANSFORM_SED+= \
	-e "s|${BUILDLINK_PREFIX.gettext}/lib/libintl.la|-L${BUILDLINK_PREFIX.gettext}/lib -lintl|g" \
	-e "s|${LOCALBASE}/lib/libintl.la|-L${BUILDLINK_PREFIX.gettext}/lib -lintl|g"
.endif

gettext-buildlink: _BUILDLINK_USE

gettext-libintl-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libintl.la";			\
	libpattern="${BUILDLINK_PREFIX.gettext}/lib/libintl.*";		\
	${BUILDLINK_FAKE_LA}

.endif	# GETTEXT_BUILDLINK2_MK
