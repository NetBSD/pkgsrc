# $NetBSD: buildlink3.mk,v 1.3 2016/03/09 20:45:44 fhajny Exp $

BUILDLINK_TREE+=	liblognorm

.if !defined(LIBLOGNORM_BUILDLINK3_MK)
LIBLOGNORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblognorm+=	liblognorm>=1.0.0
BUILDLINK_PKGSRCDIR.liblognorm?=	../../sysutils/liblognorm

.include "../../devel/libestr/buildlink3.mk"
.include "../../textproc/libfastjson/buildlink3.mk"
.endif # LIBLOGNORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblognorm
