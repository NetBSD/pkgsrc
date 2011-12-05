# $NetBSD: buildlink3.mk,v 1.4 2011/12/05 17:17:36 joerg Exp $

BUILDLINK_TREE+=	embryo

.if !defined(EMBRYO_BUILDLINK3_MK)
EMBRYO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.embryo+=	embryo>=1.1.0
BUILDLINK_PKGSRCDIR.embryo?=	../../lang/embryo

.include "../../devel/eina/buildlink3.mk"
.endif # EMBRYO_BUILDLINK3_MK

BUILDLINK_TREE+=	-embryo
