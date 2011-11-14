# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/11/14 19:38:24 ryoon Exp $

BUILDLINK_TREE+=	libalac

.if !defined(LIBALAC_BUILDLINK3_MK)
LIBALAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libalac+=	libalac>=3
BUILDLINK_PKGSRCDIR.libalac?=	../../audio/libalac
.endif	# LIBALAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libalac
