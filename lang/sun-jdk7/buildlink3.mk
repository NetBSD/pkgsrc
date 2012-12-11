# $NetBSD: buildlink3.mk,v 1.1 2012/12/11 14:51:33 ryoon Exp $

BUILDLINK_TREE+=	sun-jdk7

.if !defined(SUN_JDK7_BUILDLINK3_MK)
SUN_JDK7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jdk7+=	sun-jdk7-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jdk7+=	sun-jdk7>=7.0.9
BUILDLINK_PKGSRCDIR.sun-jdk7?=	../../lang/sun-jdk7
BUILDLINK_DEPMETHOD.sun-jdk7?= build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.sun-jre7}

BUILDLINK_CPPFLAGS.sun-jdk7=						\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre7}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre7}/include/linux

.include "../../lang/sun-jre7/buildlink3.mk"
.endif # SUN_JDK7_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jdk7
