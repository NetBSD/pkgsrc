# $NetBSD: buildlink3.mk,v 1.2 2013/10/16 16:47:29 richard Exp $

BUILDLINK_TREE+=	sun-jre7

.if !defined(SUN_JRE7_BUILDLINK3_MK)
SUN_JRE7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jre7+=		sun-jre7-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jre7+=		sun-jre7>=7.0.9
BUILDLINK_PKGSRCDIR.sun-jre7?=		../../lang/sun-jre7

CHECK_BUILTIN.sun-jre7:=	yes
.include "../../lang/sun-jre7/builtin.mk"
CHECK_BUILTIN.sun-jre7:=	no

.if !empty(USE_BUILTIN.sun-jre7:M[yY][eE][sS])
BUILDLINK_JAVA_PREFIX.sun-jre7=	${JAVAVM7}
.else
BUILDLINK_JAVA_PREFIX.sun-jre7=	${PREFIX}/java/sun-7
.endif

UNLIMIT_RESOURCES+=	datasize	# Must be at least 131204
.endif # SUN_JRE7_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jre7
