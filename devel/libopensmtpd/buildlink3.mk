# $NetBSD: buildlink3.mk,v 1.1 2023/09/02 21:32:11 vins Exp $

BUILDLINK_TREE+=	libopensmtpd

.if !defined(LIBOPENSMTPD_BUILDLINK3_MK)
LIBOPENSMTPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopensmtpd+=	libopensmtpd>=0.7
BUILDLINK_PKGSRCDIR.libopensmtpd?=	../../devel/libopensmtpd

.endif	# LIBOPENSMTPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopensmtpd
