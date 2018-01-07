# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:20 rillig Exp $

BUILDLINK_TREE+=	openjdk8

.if !defined(OPENJDK8_BUILDLINK3_MK)
OPENJDK8_BUILDLINK3_MK:=

LIBDIR_ARCH=			${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
BUILDLINK_LIBDIRS.openjdk8+=	java/openjdk8/jre/lib/${LIBDIR_ARCH}/server
BUILDLINK_LIBDIRS.openjdk8+=	java/openjdk8/jre/lib/${LIBDIR_ARCH}

BUILDLINK_API_DEPENDS.openjdk8+=	openjdk8>=1.8.0
BUILDLINK_PKGSRCDIR.openjdk8?=		../../lang/openjdk8

.endif	# OPENJDK8_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk8
