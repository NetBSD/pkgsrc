# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:12 rillig Exp $

BUILDLINK_TREE+=	py-fuse-bindings

.if !defined(PY_FUSE_BINDINGS_BUILDLINK3_MK)
PY_FUSE_BINDINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-fuse-bindings+=	${PYPKGPREFIX}-fuse-bindings>=0.2pre1
BUILDLINK_PKGSRCDIR.py-fuse-bindings?=		../../filesystems/py-fuse-bindings
.endif # PY_FUSE_BINDINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-fuse-bindings
