# $NetBSD: buildlink2.mk,v 1.1.2.4 2002/06/27 21:35:09 jlam Exp $

.if !defined(GETTEXT_BUILDLINK2_MK)
GETTEXT_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.gettext?=	gettext-lib>=0.10.35nb1
BUILDLINK_PKGSRCDIR.gettext?=	../../devel/gettext-lib

.if defined(USE_GNU_GETTEXT)
_NEED_GNU_GETTEXT=	YES
.elif exists(/usr/include/libintl.h)
_NEED_GNU_GETTEXT=	NO
.else
_NEED_GNU_GETTEXT=	YES
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

.if ${OPSYS} != "Linux"
.  if defined(GNU_CONFIGURE)
#
# Add -lintl to LIBS in CONFIGURE_ENV to work around broken gettext.m4:
# gettext.m4 does not add -lintl where it should, and the resulting
# configure script fails to detect if libintl.a is the genuine GNU gettext
# or not.
#
INTLLIBS=		# empty
.    if ${_NEED_GNU_GETTEXT} == "YES"
INTLLIBS+=		-L${BUILDLINK_PREFIX.gettext}/lib
.        if ${_USE_RPATH} == "yes"
INTLLIBS+=		-Wl,-R${BUILDLINK_PREFIX.gettext}/lib
.        endif
.    endif
INTLLIBS+=		-lintl
LIBS+=			${INTLLIBS}
CONFIGURE_ENV+=		INTLLIBS="${INTLLIBS}"
.  endif
.endif

.if ${_NEED_GNU_GETTEXT} == "NO"
LIBTOOL_ARCHIVE_UNTRANSFORM_SED+= \
	-e "s|${LOCALBASE}/lib/libintl.la|-L${BUILDLINK_PREFIX.gettext}/lib -lintl|g"
.endif

gettext-buildlink: _BUILDLINK_USE

.endif	# GETTEXT_BUILDLINK2_MK
