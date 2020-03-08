# $NetBSD: buildlink3.mk,v 1.15 2020/03/08 16:47:53 wiz Exp $

BUILDLINK_TREE+=	claws-mail

.if !defined(CLAWS_MAIL_BUILDLINK3_MK)
CLAWS_MAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.claws-mail+=	claws-mail>=3.7.0
BUILDLINK_ABI_DEPENDS.claws-mail+=	claws-mail>=3.17.4nb3
BUILDLINK_PKGSRCDIR.claws-mail?=	../../mail/claws-mail

.include "../../textproc/enchant2/buildlink3.mk"
.endif # CLAWS_MAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-claws-mail
