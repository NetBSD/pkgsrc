# $NetBSD: buildlink.mk,v 1.2 2002/07/12 15:59:45 wiz Exp $
#
# This Makefile fragment is included by packages that use bonobo-activation.
#
# This file was created automatically using createbuildlink 1.6.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.bonobo-activation to the dependency pattern
#     for the version of bonobo-activation desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(BONOBO_ACTIVATION_BUILDLINK_MK)
BONOBO_ACTIVATION_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.bonobo-activation?=		bonobo-activation>=1.0.2
DEPENDS+=	${BUILDLINK_DEPENDS.bonobo-activation}:../../devel/bonobo-activation

EVAL_PREFIX+=	BUILDLINK_PREFIX.bonobo-activation=bonobo-activation
BUILDLINK_PREFIX.bonobo-activation_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/Bonobo_Activation_types.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/Bonobo_GenericFactory.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/Bonobo_Unknown.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-activate.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-async.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-base-service.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-id.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-init.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-register.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-server-info.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-shlib.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation-version.h
BUILDLINK_FILES.bonobo-activation+=	include/bonobo-activation-2.0/bonobo-activation/bonobo-activation.h
BUILDLINK_FILES.bonobo-activation+=	lib/bonobo/servers/Bonobo_CosNaming_NamingContext.server
BUILDLINK_FILES.bonobo-activation+=	lib/bonobo/servers/broken.server
BUILDLINK_FILES.bonobo-activation+=	lib/bonobo/servers/empty.server
BUILDLINK_FILES.bonobo-activation+=	lib/bonobo/servers/plugin.server
BUILDLINK_FILES.bonobo-activation+=	lib/libbonobo-activation.*
BUILDLINK_FILES.bonobo-activation+=	lib/pkgconfig/bonobo-activation-2.0.pc

.include "../../textproc/libxml2/buildlink.mk"
.include "../../net/ORBit2/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"

BUILDLINK_TARGETS.bonobo-activation=	bonobo-activation-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.bonobo-activation}
BUILDLINK_TARGETS+=		${BUILDLINK_PKG_CONFIG}

pre-configure: ${BUILDLINK_TARGETS}
bonobo-activation-buildlink: _BUILDLINK_USE

.endif	# BONOBO_ACTIVATION_BUILDLINK_MK
