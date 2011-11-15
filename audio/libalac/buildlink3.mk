# $NetBSD: buildlink3.mk,v 1.2 2011/11/15 23:18:56 wiz Exp $

BUILDLINK_TREE+=	libalac

.if !defined(LIBALAC_BUILDLINK3_MK)
LIBALAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libalac+=	libalac>=0.0.20111026
BUILDLINK_PKGSRCDIR.libalac?=	../../audio/libalac
.endif	# LIBALAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libalac
