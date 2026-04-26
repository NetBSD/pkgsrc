# $NetBSD: buildlink3.mk,v 1.1 2026/04/26 08:46:05 adam Exp $

BUILDLINK_TREE+=	oracle-jdk25

.if !defined(ORACLE_JDK25_BUILDLINK3_MK)
ORACLE_JDK25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oracle-jdk25+=	oracle-jdk25-[0-9]*
BUILDLINK_ABI_DEPENDS.oracle-jdk25+=	oracle-jdk25>=25.0.3
BUILDLINK_PKGSRCDIR.oracle-jdk25?=	../../lang/oracle-jdk25
BUILDLINK_JAVA_PREFIX.oracle-jdk25=	${PREFIX}/java/oracle-jdk25

UNLIMIT_RESOURCES+=	datasize
.endif # ORACLE_JDK25_BUILDLINK3_MK

BUILDLINK_TREE+=	-oracle-jdk25
