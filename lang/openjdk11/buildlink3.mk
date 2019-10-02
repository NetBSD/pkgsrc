# $NetBSD: buildlink3.mk,v 1.1 2019/10/02 13:10:23 ryoon Exp $

BUILDLINK_TREE+=	openjdk11

.if !defined(OPENJDK11_BUILDLINK3_MK)
OPENJDK11_BUILDLINK3_MK:=

LIBDIR_ARCH=			${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
BUILDLINK_LIBDIRS.openjdk11+=	java/openjdk11/jre/lib/${LIBDIR_ARCH}/server
BUILDLINK_LIBDIRS.openjdk11+=	java/openjdk11/jre/lib/${LIBDIR_ARCH}

BUILDLINK_API_DEPENDS.openjdk11+=	openjdk11>=1.11.0.5.8
BUILDLINK_PKGSRCDIR.openjdk11?=		../../lang/openjdk11

.endif	# OPENJDK11_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk11
