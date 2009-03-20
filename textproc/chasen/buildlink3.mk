# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:28 joerg Exp $

BUILDLINK_TREE+=	chasen

.if !defined(CHASEN_BUILDLINK3_MK)
CHASEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chasen+=	chasen>=2.0
BUILDLINK_PKGSRCDIR.chasen?=	../../textproc/chasen
BUILDLINK_FILES.chasen=		include/chasen.h
BUILDLINK_FILES.chasen+=	lib/libchasen.*
.endif # CHASEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-chasen
