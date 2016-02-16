# $NetBSD: buildlink3.mk,v 1.2 2016/02/16 15:17:51 fhajny Exp $

BUILDLINK_TREE+=	liblognorm

.if !defined(LIBLOGNORM_BUILDLINK3_MK)
LIBLOGNORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblognorm+=	liblognorm>=1.0.0
BUILDLINK_PKGSRCDIR.liblognorm?=	../../sysutils/liblognorm

.include "../../devel/libestr/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.endif # LIBLOGNORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblognorm
