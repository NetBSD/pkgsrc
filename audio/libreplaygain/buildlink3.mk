# $NetBSD: buildlink3.mk,v 1.1 2014/04/18 12:41:09 wiz Exp $

BUILDLINK_TREE+=	libreplaygain

.if !defined(LIBREPLAYGAIN_BUILDLINK3_MK)
LIBREPLAYGAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libreplaygain+=	libreplaygain>=0rc475
BUILDLINK_PKGSRCDIR.libreplaygain?=	../../audio/libreplaygain
.endif	# LIBREPLAYGAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libreplaygain
