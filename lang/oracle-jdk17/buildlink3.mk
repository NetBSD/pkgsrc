# $NetBSD: buildlink3.mk,v 1.1 2022/12/02 10:48:38 jperkin Exp $

BUILDLINK_TREE+=	oracle-jdk17

.if !defined(ORACLE_JDK17_BUILDLINK3_MK)
ORACLE_JDK17_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oracle-jdk17+=	oracle-jdk17-[0-9]*
BUILDLINK_ABI_DEPENDS.oracle-jdk17+=	oracle-jdk17>=17.0.5
BUILDLINK_PKGSRCDIR.oracle-jdk17?=	../../lang/oracle-jdk17
BUILDLINK_JAVA_PREFIX.oracle-jdk17=	${PREFIX}/java/oracle-jdk17

UNLIMIT_RESOURCES+=	datasize
.endif # ORACLE_JDK17_BUILDLINK3_MK

BUILDLINK_TREE+=	-oracle-jdk17
