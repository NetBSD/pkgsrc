# $NetBSD: buildlink3.mk,v 1.5 2022/04/01 11:44:41 nia Exp $

BUILDLINK_TREE+=	celt

.if !defined(CELT_BUILDLINK3_MK)
CELT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.celt+=	celt>=0.11.3
BUILDLINK_PKGSRCDIR.celt?=	../../audio/celt
BUILDLINK_INCDIRS.celt+=	include/celt

pkgbase:= celt
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.celt:Mogg)
.  include "../../multimedia/libogg/buildlink3.mk"
.endif
.endif # CELT_BUILDLINK3_MK

BUILDLINK_TREE+=	-celt
