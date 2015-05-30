# $NetBSD: buildlink3.mk,v 1.1 2015/05/30 09:49:43 ryoon Exp $

BUILDLINK_TREE+=	oracle-jre8

.if !defined(ORACLE_JRE8_BUILDLINK3_MK)
ORACLE_JRE8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oracle-jre8+=		oracle-jre8-[0-9]*
BUILDLINK_ABI_DEPENDS.oracle-jre8+=		oracle-jre8>=8.0.45
BUILDLINK_PKGSRCDIR.oracle-jre8?=		../../lang/oracle-jre8

CHECK_BUILTIN.oracle-jre8:=	yes
.include "../../lang/oracle-jre8/builtin.mk"
CHECK_BUILTIN.oracle-jre8:=	no

.if !empty(USE_BUILTIN.oracle-jre8:M[yY][eE][sS])
BUILDLINK_JAVA_PREFIX.oracle-jre8=	${JAVAVM8}
.else
BUILDLINK_JAVA_PREFIX.oracle-jre8=	${PREFIX}/java/oracle-8
.endif

UNLIMIT_RESOURCES+=	datasize	# Must be at least 131204
.endif # ORACLE_JRE8_BUILDLINK3_MK

BUILDLINK_TREE+=	-oracle-jre8
