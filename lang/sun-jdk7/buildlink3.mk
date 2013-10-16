# $NetBSD: buildlink3.mk,v 1.3 2013/10/16 16:48:55 richard Exp $

BUILDLINK_TREE+=	sun-jdk7

.if !defined(SUN_JDK7_BUILDLINK3_MK)
SUN_JDK7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jdk7+=	sun-jdk7-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jdk7+=	sun-jdk7>=7.0.9
BUILDLINK_PKGSRCDIR.sun-jdk7?=	../../lang/sun-jdk7
BUILDLINK_DEPMETHOD.sun-jdk7?= build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.sun-jre7}

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_CPPFLAGS.sun-jdk7=						\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre7}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre7}/include/solaris
.else
BUILDLINK_CPPFLAGS.sun-jdk7=						\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre7}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre7}/include/linux
.endif

BUILDLINK_DEPMETHOD.sun-jre7?=	${BUILDLINK_DEPMETHOD.sun-jdk7}
.include "../../lang/sun-jre7/buildlink3.mk"
.endif # SUN_JDK7_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jdk7
