# $NetBSD: buildlink3.mk,v 1.1 2014/11/30 18:58:43 adam Exp $

BUILDLINK_TREE+=	fdk-aac

.if !defined(FDK_AAC_BUILDLINK3_MK)
FDK_AAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fdk-aac+=	fdk-aac>=0.1.3
BUILDLINK_PKGSRCDIR.fdk-aac?=	../../audio/fdk-aac
.endif	# FDK_AAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-fdk-aac
