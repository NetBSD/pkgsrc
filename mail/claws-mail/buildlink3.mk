# $NetBSD: buildlink3.mk,v 1.21 2026/09/27 11:37:22 tnn Exp $

BUILDLINK_TREE+=	claws-mail

.if !defined(CLAWS_MAIL_BUILDLINK3_MK)
CLAWS_MAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.claws-mail+=	claws-mail>=3.7.0
BUILDLINK_ABI_DEPENDS.claws-mail+=	claws-mail>=4.3.1nb37
BUILDLINK_PKGSRCDIR.claws-mail?=	../../mail/claws-mail

.include "../../textproc/enchant2/buildlink3.mk"
.endif # CLAWS_MAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-claws-mail
