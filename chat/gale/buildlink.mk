# $NetBSD: buildlink.mk,v 1.1 2001/11/19 21:05:55 jlam Exp $
#
# This Makefile fragment is included by packages that use gale.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gale to the dependency pattern
#     for the version of gale desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GALE_BUILDLINK_MK)
GALE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gale?=	gale>=0.99
DEPENDS+=	${BUILDLINK_DEPENDS.gale}:../../chat/gale

EVAL_PREFIX+=			BUILDLINK_PREFIX.gale=gale
BUILDLINK_PREFIX.gale_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gale=		include/gale/*.h
BUILDLINK_FILES.gale+=		include/oop-adns.h
BUILDLINK_FILES.gale+=		include/oop-glib.h
BUILDLINK_FILES.gale+=		include/oop-www.h
BUILDLINK_FILES.gale+=		include/oop.h
BUILDLINK_FILES.gale+=		lib/libgale.*
BUILDLINK_FILES.gale+=		lib/liboop-adns.*
BUILDLINK_FILES.gale+=		lib/liboop-glib.*
BUILDLINK_FILES.gale+=		lib/liboop-www.*
BUILDLINK_FILES.gale+=		lib/liboop.*

.include "../../devel/glib/buildlink.mk"
.include "../../net/adns/buildlink.mk"
.include "../../security/rsaref/buildlink.mk"
.include "../../www/libwww/buildlink.mk"

BUILDLINK_TARGETS.gale=		gale-buildlink
BUILDLINK_TARGETS.gale+=	gale-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gale}

BUILDLINK_CONFIG.gale=		${BUILDLINK_PREFIX.gale}/bin/gale-config
BUILDLINK_CONFIG_WRAPPER.gale=	${BUILDLINK_DIR}/bin/gale-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gale}|${BUILDLINK_CONFIG.gale}|g"

.if defined(USE_CONFIG_WRAPPER)
GALE_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gale}
CONFIGURE_ENV+=		GALE_CONFIG="${GALE_CONFIG}"
MAKE_ENV+=		GALE_CONFIG="${GALE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gale}
gale-buildlink: _BUILDLINK_USE
gale-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GALE_BUILDLINK_MK
