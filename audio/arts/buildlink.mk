# $NetBSD: buildlink.mk,v 1.1.1.1.2.2 2002/06/23 18:37:29 jlam Exp $
#
# This Makefile fragment is included by packages that use arts.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.arts to the dependency pattern
#     for the version of arts desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ARTS_BUILDLINK_MK)
ARTS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.arts?=	arts>=1.0.0
DEPENDS+=	${BUILDLINK_DEPENDS.arts}:../../audio/arts

EVAL_PREFIX+=			BUILDLINK_PREFIX.arts=arts
BUILDLINK_PREFIX.arts_DEFAULT=	${X11BASE}

BUILDLINK_FILES.arts!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../audio/arts/PLIST

BUILDLINK_TARGETS.arts=		arts-buildlink
BUILDLINK_TARGETS.arts+=	artsc-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.arts}

BUILDLINK_CONFIG.artsc=	\
			${BUILDLINK_PREFIX.arts}/bin/artsc-config
BUILDLINK_CONFIG_WRAPPER.artsc=	\
			${BUILDLINK_DIR}/bin/artsc-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.artsc}|${BUILDLINK_CONFIG.artsc}|g"

.if defined(USE_CONFIG_WRAPPER)
ARTSC_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.artsc}
CONFIGURE_ENV+=		ARTSC_CONFIG="${ARTSC_CONFIG}"
MAKE_ENV+=		ARTSC_CONFIG="${ARTSC_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.arts}
arts-buildlink: _BUILDLINK_USE
artsc-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# ARTS_BUILDLINK_MK
