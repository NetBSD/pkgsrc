# $NetBSD: buildlink3.mk,v 1.12 2026/01/27 08:39:48 wiz Exp $

BUILDLINK_TREE+=	ruby-cairo

.if !defined(RUBY_CAIRO_BUILDLINK3_MK)
RUBY_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-cairo+=	${RUBY_PKGPREFIX}-cairo>=1.6.0
BUILDLINK_ABI_DEPENDS.ruby-cairo+=	${RUBY_PKGPREFIX}-cairo>=1.18.4nb2
BUILDLINK_PKGSRCDIR.ruby-cairo?=	../../graphics/ruby-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # RUBY_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-cairo
