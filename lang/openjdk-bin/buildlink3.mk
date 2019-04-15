# $NetBSD: buildlink3.mk,v 1.1 2019/04/15 14:25:25 ryoon Exp $

BUILDLINK_TREE+=	openjdk-bin

.if !defined(OPENJDK_BIN_BUILDLINK3_MK)
OPENJDK_BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjdk-bin+=	openjdk-bin>=12
BUILDLINK_PKGSRCDIR.openjdk-bin?=	../../lang/openjdk-bin

BUILDLINK_JAVA_PREFIX.openjdk-bin=	${PREFIX}/java/openjdk-bin

.endif	# OPENJDK_BIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk-bin
