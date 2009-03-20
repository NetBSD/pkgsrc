# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:52 joerg Exp $

BUILDLINK_TREE+=	sun-jre14

.if !defined(SUN_JRE14_BUILDLINK3_MK)
SUN_JRE14_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jre14+=		sun-jre14-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jre14?=	sun-jre14>=2.11
BUILDLINK_PKGSRCDIR.sun-jre14?=		../../lang/sun-jre14
BUILDLINK_JAVA_PREFIX.sun-jre14=	${PREFIX}/java/sun-1.4

UNLIMIT_RESOURCES+=	datasize	# Must be at least 131204
.endif # SUN_JRE14_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jre14
