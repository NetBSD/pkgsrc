# $NetBSD: buildlink3.mk,v 1.14 2018/12/01 17:31:06 bsiegert Exp $

BUILDLINK_TREE+=	claws-mail

.if !defined(CLAWS_MAIL_BUILDLINK3_MK)
CLAWS_MAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.claws-mail+=	claws-mail>=3.7.0
BUILDLINK_ABI_DEPENDS.claws-mail+=	claws-mail>=3.11.1
BUILDLINK_PKGSRCDIR.claws-mail?=	../../mail/claws-mail

.include "../../textproc/enchant2/buildlink3.mk"
.endif # CLAWS_MAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-claws-mail
