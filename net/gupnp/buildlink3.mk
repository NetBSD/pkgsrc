# $NetBSD: buildlink3.mk,v 1.28 2015/06/07 14:14:04 youri Exp $

BUILDLINK_TREE+=	gupnp

.if !defined(GUPNP_BUILDLINK3_MK)
GUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp+=	gupnp>=0.20.3
BUILDLINK_ABI_DEPENDS.gupnp+=	gupnp>=0.20.13nb2
BUILDLINK_PKGSRCDIR.gupnp?=	../../net/gupnp

.include "../../mk/bsd.fast.prefs.mk"
.if (!empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin") && (!defined(USE_INTERNAL_UUID) || empty(USE_INTERNAL_UUID:M[Yy][Ee][Ss]))
pre-configure:
	cp ${BUILDLINK_PKGSRCDIR.gupnp}/files/uuid.pc ${BUILDLINK_DIR}/lib/pkgconfig/
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# GUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp
