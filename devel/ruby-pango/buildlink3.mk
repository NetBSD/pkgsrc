# $NetBSD: buildlink3.mk,v 1.26 2025/10/23 20:36:38 wiz Exp $

BUILDLINK_TREE+=	ruby-pango

.if !defined(RUBY_PANGO_BUILDLINK3_MK)
RUBY_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=4.3.3
BUILDLINK_ABI_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=4.3.3nb1
BUILDLINK_PKGSRCDIR.ruby-pango?=	../../devel/ruby-pango

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-pango
