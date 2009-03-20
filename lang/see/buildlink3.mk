# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:52 joerg Exp $

BUILDLINK_TREE+=	see

.if !defined(SEE_BUILDLINK3_MK)
SEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.see+=	see>=3.0.1376
BUILDLINK_PKGSRCDIR.see?=	../../lang/see

.include "../../devel/readline/buildlink3.mk"
.endif # SEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-see
