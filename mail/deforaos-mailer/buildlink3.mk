# $NetBSD: buildlink3.mk,v 1.2 2016/08/03 10:22:16 adam Exp $

BUILDLINK_TREE+=	deforaos-mailer

.if !defined(DEFORAOS_MAILER_BUILDLINK3_MK)
DEFORAOS_MAILER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-mailer+=	deforaos-mailer>=0.1.6
BUILDLINK_ABI_DEPENDS.deforaos-mailer?=	deforaos-mailer>=0.1.8nb1
BUILDLINK_PKGSRCDIR.deforaos-mailer?=	../../mail/deforaos-mailer

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_MAILER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-mailer
