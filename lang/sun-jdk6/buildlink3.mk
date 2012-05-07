# $NetBSD: buildlink3.mk,v 1.5 2012/05/07 01:53:43 dholland Exp $

BUILDLINK_TREE+=	sun-jdk6

.if !defined(SUN_JDK6_BUILDLINK3_MK)
SUN_JDK6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jdk6+=	sun-jdk6-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jdk6+=	sun-jdk6>=6.0.4
BUILDLINK_PKGSRCDIR.sun-jdk6?=	../../lang/sun-jdk6
BUILDLINK_DEPMETHOD.sun-jdk6?= build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.sun-jre6}

BUILDLINK_CPPFLAGS.sun-jdk6=						\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre6}/include/linux

.include "../../lang/sun-jre6/buildlink3.mk"
.endif # SUN_JDK6_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jdk6
