# $NetBSD: buildlink3.mk,v 1.2 2008/07/13 22:32:05 smb Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
CLAWS_MAIL_PGPCORE_BUILDLINK3_MK:=	${CLAWS_MAIL_PGPCORE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	claws-mail-pgpcore
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclaws-mail-pgpcore}
BUILDLINK_PACKAGES+=	claws-mail-pgpcore
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}claws-mail-pgpcore

.if ${CLAWS_MAIL_PGPCORE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.claws-mail-pgpcore+=	claws-mail-pgpcore>=3.5.0
BUILDLINK_PKGSRCDIR.claws-mail-pgpcore?=	../../mail/claws-mail-pgpcore
.endif	# CLAWS_MAIL_PGPCORE_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
