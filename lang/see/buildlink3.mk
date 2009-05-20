# $NetBSD: buildlink3.mk,v 1.3 2009/05/20 00:58:20 wiz Exp $

BUILDLINK_TREE+=	see

.if !defined(SEE_BUILDLINK3_MK)
SEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.see+=	see>=3.0.1376
BUILDLINK_ABI_DEPENDS.see?=	see>=3.0.1376nb2
BUILDLINK_PKGSRCDIR.see?=	../../lang/see

.include "../../devel/readline/buildlink3.mk"
.endif # SEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-see
