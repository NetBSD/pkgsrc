# $NetBSD: buildlink3.mk,v 1.5 2013/06/16 18:56:05 sno Exp $

BUILDLINK_TREE+=	embryo

.if !defined(EMBRYO_BUILDLINK3_MK)
EMBRYO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.embryo+=	embryo>=1.7.7
BUILDLINK_PKGSRCDIR.embryo?=	../../lang/embryo

.include "../../devel/eina/buildlink3.mk"
.endif # EMBRYO_BUILDLINK3_MK

BUILDLINK_TREE+=	-embryo
