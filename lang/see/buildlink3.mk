# $NetBSD: buildlink3.mk,v 1.6 2022/06/28 11:34:15 wiz Exp $

BUILDLINK_TREE+=	see

.if !defined(SEE_BUILDLINK3_MK)
SEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.see+=	see>=3.0.1376
BUILDLINK_ABI_DEPENDS.see+=	see>=3.0.1376nb16
BUILDLINK_PKGSRCDIR.see?=	../../lang/see

.include "../../mk/readline.buildlink3.mk"
.endif # SEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-see
