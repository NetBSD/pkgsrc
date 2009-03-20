# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:48 joerg Exp $

BUILDLINK_TREE+=	embryo

.if !defined(EMBRYO_BUILDLINK3_MK)
EMBRYO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.embryo+=	embryo>=0.9.5.050
BUILDLINK_PKGSRCDIR.embryo?=	../../lang/embryo
.endif # EMBRYO_BUILDLINK3_MK

BUILDLINK_TREE+=	-embryo
