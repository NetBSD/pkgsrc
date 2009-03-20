# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:24:54 joerg Exp $

BUILDLINK_TREE+=	claws-mail

.if !defined(CLAWS_MAIL_BUILDLINK3_MK)
CLAWS_MAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.claws-mail+= claws-mail>=3.7.0
BUILDLINK_PKGSRCDIR.claws-mail?=	../../mail/claws-mail
.endif # CLAWS_MAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-claws-mail
