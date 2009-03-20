# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:33 joerg Exp $

BUILDLINK_TREE+=	py-fuse-bindings

.if !defined(PY_FUSE_BINDINGS_BUILDLINK3_MK)
PY_FUSE_BINDINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-fuse-bindings+=	${PYPKGPREFIX}-fuse-bindings>=0.2pre1
BUILDLINK_PKGSRCDIR.py-fuse-bindings?=	../../filesystems/py-fuse-bindings
.endif # PY_FUSE_BINDINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-fuse-bindings
