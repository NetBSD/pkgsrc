# $NetBSD: buildlink3.mk,v 1.1 2024/03/12 17:50:12 wiz Exp $

BUILDLINK_TREE+=	gprbuild

.if !defined(GPRBUILD_BUILDLINK3_MK)
GPRBUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprbuild+=	gprbuild>=24
BUILDLINK_ABI_DEPENDS.gprbuild+=	gprbuild>=24.0.0
BUILDLINK_PKGSRCDIR.gprbuild=		../../devel/gprbuild
BUILDLINK_DEPMETHOD.gprbuild?=		build

BUILDLINK_FILES.gprbuild+=	bin/gpr* libexec/gprbuild/* share/gpr/* share/gprbuild/*

.endif

BUILDLINK_TREE+=	-gprbuild
