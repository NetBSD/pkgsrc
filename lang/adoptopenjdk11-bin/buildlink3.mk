# $NetBSD: buildlink3.mk,v 1.1 2020/01/13 01:38:42 ryoon Exp $
BUILDLINK_TREE+=	adoptopenjdk11

.if !defined(ADOPTOPENJDK11_BUILDLINK3_MK)
ADOPTOPENJDK11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adoptopenjdk11+=	adoptopenjdk11>=11.0.5.10
BUILDLINK_PKGSRCDIR.adoptopenjdk11?=	../../lang/adoptopenjdk11-bin

BUILDLINK_JAVA_PREFIX.adoptopenjdk11-bin=	${PREFIX}/java/adoptopenjdk11-bin
.endif	# ADOPTOPENJDK11_BUILDLINK3_MK

BUILDLINK_TREE+=	-adoptopenjdk11
