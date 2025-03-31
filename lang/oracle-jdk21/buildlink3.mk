# $NetBSD: buildlink3.mk,v 1.1 2025/03/31 09:33:32 adam Exp $

BUILDLINK_TREE+=	oracle-jdk21

.if !defined(ORACLE_JDK21_BUILDLINK3_MK)
ORACLE_JDK21_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oracle-jdk21+=	oracle-jdk21-[0-9]*
BUILDLINK_ABI_DEPENDS.oracle-jdk21+=	oracle-jdk21>=21.0.5
BUILDLINK_PKGSRCDIR.oracle-jdk21?=	../../lang/oracle-jdk21
BUILDLINK_JAVA_PREFIX.oracle-jdk21=	${PREFIX}/java/oracle-jdk21

UNLIMIT_RESOURCES+=	datasize
.endif # ORACLE_JDK21_BUILDLINK3_MK

BUILDLINK_TREE+=	-oracle-jdk21
