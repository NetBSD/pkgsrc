# $NetBSD: buildlink3.mk,v 1.1 2021/10/10 01:59:31 dsainty Exp $

BUILDLINK_TREE+=	java-rxtx

.if !defined(JAVA_RXTX_BUILDLINK3_MK)
JAVA_RXTX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.java-rxtx+=	java-rxtx>=2.1.7r2
BUILDLINK_PKGSRCDIR.java-rxtx?=	../../comms/java-rxtx
BUILDLINK_LIBDIRS.java-rxtx+=		lib/java/rxtx

.endif	# JAVA_RXTX_BUILDLINK3_MK

BUILDLINK_TREE+=	-java-rxtx
