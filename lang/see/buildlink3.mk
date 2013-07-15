# $NetBSD: buildlink3.mk,v 1.5 2013/07/15 02:02:24 ryoon Exp $

BUILDLINK_TREE+=	see

.if !defined(SEE_BUILDLINK3_MK)
SEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.see+=	see>=3.0.1376
BUILDLINK_ABI_DEPENDS.see+=	see>=3.0.1376nb2
BUILDLINK_PKGSRCDIR.see?=	../../lang/see

.include "../../mk/readline.buildlink3.mk"
.endif # SEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-see
