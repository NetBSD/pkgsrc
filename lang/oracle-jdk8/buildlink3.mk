# $NetBSD: buildlink3.mk,v 1.1 2015/05/30 09:51:11 ryoon Exp $

BUILDLINK_TREE+=	oracle-jdk8

.if !defined(ORACLE_JDK8_BUILDLINK3_MK)
ORACLE_JDK8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oracle-jdk8+=	oracle-jdk8-[0-9]*
BUILDLINK_ABI_DEPENDS.oracle-jdk8+=	oracle-jdk8>=8.0.45
BUILDLINK_PKGSRCDIR.oracle-jdk8?=	../../lang/oracle-jdk8
BUILDLINK_DEPMETHOD.oracle-jdk8?= build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.oracle-jre8}

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_CPPFLAGS.oracle-jdk8=						\
	-I${BUILDLINK_JAVA_PREFIX.oracle-jre8}/include			\
	-I${BUILDLINK_JAVA_PREFIX.oracle-jre8}/include/solaris
.else
BUILDLINK_CPPFLAGS.oracle-jdk8=						\
	-I${BUILDLINK_JAVA_PREFIX.oracle-jre8}/include			\
	-I${BUILDLINK_JAVA_PREFIX.oracle-jre8}/include/linux
.endif

BUILDLINK_DEPMETHOD.oracle-jre8?=	${BUILDLINK_DEPMETHOD.oracle-jdk8}
.include "../../lang/oracle-jre8/buildlink3.mk"
.endif # ORACLE_JDK8_BUILDLINK3_MK

BUILDLINK_TREE+=	-oracle-jdk8
