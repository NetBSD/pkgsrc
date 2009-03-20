# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:52 joerg Exp $

BUILDLINK_TREE+=	sun-jre15

.if !defined(SUN_JRE15_BUILDLINK3_MK)
SUN_JRE15_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jre15+=		sun-jre15-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jre15?=		sun-jre15>=5.0.6nb2
BUILDLINK_PKGSRCDIR.sun-jre15?=		../../lang/sun-jre15
BUILDLINK_JAVA_PREFIX.sun-jre15=	${PREFIX}/java/sun-1.5

UNLIMIT_RESOURCES+=	datasize	# Must be at least 131204
.endif # SUN_JRE15_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jre15
