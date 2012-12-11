# $NetBSD: buildlink3.mk,v 1.1 2012/12/11 14:47:17 ryoon Exp $

BUILDLINK_TREE+=	sun-jre7

.if !defined(SUN_JRE7_BUILDLINK3_MK)
SUN_JRE7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sun-jre7+=		sun-jre7-[0-9]*
BUILDLINK_ABI_DEPENDS.sun-jre7+=		sun-jre7>=7.0.9
BUILDLINK_PKGSRCDIR.sun-jre7?=		../../lang/sun-jre7
BUILDLINK_JAVA_PREFIX.sun-jre7=	${PREFIX}/java/sun-7

UNLIMIT_RESOURCES+=	datasize	# Must be at least 131204
.endif # SUN_JRE7_BUILDLINK3_MK

BUILDLINK_TREE+=	-sun-jre7
