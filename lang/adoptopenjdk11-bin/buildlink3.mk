# $NetBSD: buildlink3.mk,v 1.2 2020/01/15 15:35:35 ryoon Exp $

BUILDLINK_TREE+=	adoptopenjdk11-bin

.if !defined(ADOPTOPENJDK11_BIN_BUILDLINK3_MK)
ADOPTOPENJDK11_BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adoptopenjdk11-bin+=	adoptopenjdk11-bin>=11.0.5.10
BUILDLINK_PKGSRCDIR.adoptopenjdk11-bin?=	../../lang/adoptopenjdk11-bin

BUILDLINK_JAVA_PREFIX.adoptopenjdk11-bin=	${PREFIX}/java/adoptopenjdk11-bin
.endif	# ADOPTOPENJDK11_BIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-adoptopenjdk11-bin
