# $NetBSD: buildlink3.mk,v 1.10 2024/04/07 07:34:20 wiz Exp $

BUILDLINK_TREE+=	ruby-cairo

.if !defined(RUBY_CAIRO_BUILDLINK3_MK)
RUBY_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-cairo+=	${RUBY_PKGPREFIX}-cairo>=1.6.0
BUILDLINK_ABI_DEPENDS.ruby-cairo+=	${RUBY_PKGPREFIX}-cairo>=1.17.12nb3
BUILDLINK_PKGSRCDIR.ruby-cairo?=	../../graphics/ruby-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # RUBY_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-cairo
