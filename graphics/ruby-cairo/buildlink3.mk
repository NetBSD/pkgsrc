# $NetBSD: buildlink3.mk,v 1.14 2026/09/27 11:37:01 tnn Exp $

BUILDLINK_TREE+=	ruby-cairo

.if !defined(RUBY_CAIRO_BUILDLINK3_MK)
RUBY_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-cairo+=	${RUBY_PKGPREFIX}-cairo>=1.6.0
BUILDLINK_ABI_DEPENDS.ruby-cairo+=	${RUBY_PKGPREFIX}-cairo>=1.18.5nb2
BUILDLINK_PKGSRCDIR.ruby-cairo?=	../../graphics/ruby-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # RUBY_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-cairo
