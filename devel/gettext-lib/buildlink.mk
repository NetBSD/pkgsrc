# $NetBSD: buildlink.mk,v 1.13 2002/02/21 12:08:32 wiz Exp $
#
# This Makefile fragment is included by packages that use gettext.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gettext to the dependency pattern
#     for the version of gettext desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GETTEXT_BUILDLINK_MK)
GETTEXT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gettext?=	gettext-lib>=0.10.35nb1

.if defined(USE_GNU_GETTEXT)
_NEED_GNU_GETTEXT=	YES
.elif exists(/usr/include/libintl.h)
_NEED_GNU_GETTEXT=	NO
.else
_NEED_GNU_GETTEXT=	YES
.endif

.if ${_NEED_GNU_GETTEXT} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.gettext}:../../devel/gettext-lib
EVAL_PREFIX+=	BUILDLINK_PREFIX.gettext=gettext-lib
BUILDLINK_PREFIX.gettext_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.gettext=	/usr
.endif

BUILDLINK_FILES.gettext=	include/libintl.h
BUILDLINK_FILES.gettext+=	lib/libintl.*

BUILDLINK_TARGETS.gettext=	gettext-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gettext}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
.if defined(GNU_CONFIGURE)
#
# Add -lintl to LIBS in CONFIGURE_ENV to work around broken gettext.m4:
# gettext.m4 does not add -lintl where it should, and the resulting
# configure script fails to detect if libintl.a is the genuine GNU gettext
# or not.
#
INTLLIBS=			-L${BUILDLINK_DIR}/lib
.if ${_NEED_GNU_GETTEXT} == "YES"
.if ${_USE_RPATH} == "yes"
INTLLIBS+=			-Wl,-R${BUILDLINK_PREFIX.gettext}/lib
.endif
.endif
INTLLIBS+=			-lintl
LIBS+=				${INTLLIBS}
CONFIGURE_ENV+=			INTLLIBS="${INTLLIBS}"
.endif
.endif

pre-configure: ${BUILDLINK_TARGETS.gettext}
gettext-buildlink: _BUILDLINK_USE

.endif	# GETTEXT_BUILDLINK_MK
