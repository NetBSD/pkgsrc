# $NetBSD: buildlink3.mk,v 1.38 2020/03/10 22:08:53 wiz Exp $

BUILDLINK_TREE+=	claws-mail-pgpcore

.if !defined(CLAWS_MAIL_PGPCORE_BUILDLINK3_MK)
CLAWS_MAIL_PGPCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.claws-mail-pgpcore+=	claws-mail-pgpcore>=3.7.0
BUILDLINK_ABI_DEPENDS.claws-mail-pgpcore+=	claws-mail-pgpcore>=3.17.4nb4
BUILDLINK_PKGSRCDIR.claws-mail-pgpcore?=	../../mail/claws-mail-pgpcore

.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.endif # CLAWS_MAIL_PGPCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-claws-mail-pgpcore
