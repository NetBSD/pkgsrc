# $NetBSD: buildlink3.mk,v 1.40 2021/08/24 13:38:18 nia Exp $

BUILDLINK_TREE+=	claws-mail-pgpcore

.if !defined(CLAWS_MAIL_PGPCORE_BUILDLINK3_MK)
CLAWS_MAIL_PGPCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.claws-mail-pgpcore+=	claws-mail-pgpcore>=3.7.0
BUILDLINK_ABI_DEPENDS.claws-mail-pgpcore+=	claws-mail-pgpcore>=3.17.5nb3
BUILDLINK_PKGSRCDIR.claws-mail-pgpcore?=	../../mail/claws-mail-pgpcore

.include "../../security/gpgme/buildlink3.mk"
.endif # CLAWS_MAIL_PGPCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-claws-mail-pgpcore
