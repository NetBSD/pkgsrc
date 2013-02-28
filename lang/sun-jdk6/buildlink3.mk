# $NetBSD: buildlink3.mk,v 1.6 2013/02/28 23:03:58 jperkin Exp $

BUILDLINK_TREE+=	sun-jdk6

.if !defined(SUN_JDK6_BUILDLINK3_MK)
SUN_JDK6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jdk6+=	sun-jdk6-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jdk6+=	sun-jdk6>=6.0.4
BUILDLINK_PKGSRCDIR.sun-jdk6?=	../../lang/sun-jdk6
BUILDLINK_DEPMETHOD.sun-jdk6?= build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.sun-jre6}

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_CPPFLAGS.sun-jdk6=						\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include/solaris
.else
BUILDLINK_CPPFLAGS.sun-jdk6=						\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include/linux
.endif

.include "../../lang/sun-jre6/buildlink3.mk"
.endif # SUN_JDK6_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jdk6
