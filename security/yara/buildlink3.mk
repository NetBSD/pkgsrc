# $NetBSD: buildlink3.mk,v 1.2 2015/06/06 08:57:18 pettai Exp $

BUILDLINK_TREE+=	yara

.if !defined(YARA_BUILDLINK3_MK)
YARA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yara+=	yara>=3.3.0
BUILDLINK_PKGSRCDIR.yara?=	../../security/yara
.endif	# YARA_BUILDLINK3_MK

BUILDLINK_TREE+=	-yara
