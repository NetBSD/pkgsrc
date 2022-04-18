# $NetBSD: buildlink3.mk,v 1.49 2022/04/18 19:10:02 adam Exp $

BUILDLINK_TREE+=	gupnp

.if !defined(GUPNP_BUILDLINK3_MK)
GUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp+=	gupnp>=0.20.3
BUILDLINK_ABI_DEPENDS.gupnp+=	gupnp>=1.0.3nb15
BUILDLINK_PKGSRCDIR.gupnp?=	../../net/gupnp

.include "../../mk/bsd.fast.prefs.mk"
.if (!empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin") && (!defined(USE_INTERNAL_UUID) || empty(USE_INTERNAL_UUID:M[Yy][Ee][Ss]))
pre-configure: gupnp-pre-configure
.PHONY: gupnp-pre-configure
gupnp-pre-configure:
	if ! ${TEST} -e ${BUILDLINK_DIR}/lib/pkgconfig/uuid.pc; then cp ${BUILDLINK_PKGSRCDIR.gupnp}/files/uuid.pc ${BUILDLINK_DIR}/lib/pkgconfig/uuid.pc; fi
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# GUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp
