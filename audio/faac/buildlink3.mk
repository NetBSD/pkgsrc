# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	faac

.if !defined(FAAC_BUILDLINK3_MK)
FAAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faac+=	faac>=1.24
BUILDLINK_ABI_DEPENDS.faac+=	faac>=1.24nb1
BUILDLINK_PKGSRCDIR.faac?=	../../audio/faac
.endif # FAAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-faac
