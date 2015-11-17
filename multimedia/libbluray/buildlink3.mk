# $NetBSD: buildlink3.mk,v 1.1 2015/11/17 00:02:50 jmcneill Exp $

BUILDLINK_TREE+=	libbluray

.if !defined(LIBBLURAY_BUILDLINK3_MK)
LIBBLURAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbluray+=	libbluray>=0.8.1
BUILDLINK_PKGSRCDIR.libbluray?=	../../multimedia/libbluray

.endif	# LIBBLURAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbluray
