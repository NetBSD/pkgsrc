# $NetBSD: buildlink3.mk,v 1.1 2013/05/15 00:41:42 rodent Exp $

BUILDLINK_TREE+=	libkate

.if !defined(LIBKATE_BUILDLINK3_MK)
LIBKATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkate+=	libkate>=0.4.1
BUILDLINK_PKGSRCDIR.libkate?=	../../multimedia/libkate

pkgbase := libkate
.include "../../mk/pkg-build-options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif	# LIBKATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkate
