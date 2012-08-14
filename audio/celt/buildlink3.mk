# $NetBSD: buildlink3.mk,v 1.3 2012/08/14 07:02:09 wiz Exp $

BUILDLINK_TREE+=	celt

.if !defined(CELT_BUILDLINK3_MK)
CELT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.celt+=	celt>=0.11.3
BUILDLINK_PKGSRCDIR.celt?=	../../audio/celt
pkgbase:= celt
.  include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.celt:Mogg)
.  include "../../multimedia/libogg/buildlink3.mk"
.endif
.endif # CELT_BUILDLINK3_MK

BUILDLINK_TREE+=	-celt
