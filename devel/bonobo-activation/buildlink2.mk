# $NetBSD: buildlink2.mk,v 1.3 2002/09/09 19:28:50 wiz Exp $

.if !defined(BONOBO_ACTIVATION_BUILDLINK2_MK)
BONOBO_ACTIVATION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=				bonobo-activation
BUILDLINK_DEPENDS.bonobo-activation?=		bonobo-activation>=1.0.2
BUILDLINK_PKGSRCDIR.bonobo-activation?=		../../devel/bonobo-activation

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
BUILDLINK_FILES.bonobo-activation+=	share/idl/bonobo-activation-2.0/*

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	bonobo-activation-buildlink

bonobo-activation-buildlink: _BUILDLINK_USE

.endif	# BONOBO_ACTIVATION_BUILDLINK2_MK
