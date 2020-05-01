# $NetBSD: buildlink3.mk,v 1.6 2020/05/01 00:14:17 joerg Exp $

BUILDLINK_TREE+=	embryo

.if !defined(EMBRYO_BUILDLINK3_MK)
EMBRYO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.embryo+=	embryo>=1.7.10
BUILDLINK_PKGSRCDIR.embryo?=	../../lang/embryo

.include "../../devel/eina/buildlink3.mk"
.endif # EMBRYO_BUILDLINK3_MK

BUILDLINK_TREE+=	-embryo
