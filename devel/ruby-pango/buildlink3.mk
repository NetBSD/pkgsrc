# $NetBSD: buildlink3.mk,v 1.20 2024/12/29 15:53:08 tsutsui Exp $

BUILDLINK_TREE+=	ruby-pango

.if !defined(RUBY_PANGO_BUILDLINK3_MK)
RUBY_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=4.2.5
BUILDLINK_ABI_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=4.2.5
BUILDLINK_PKGSRCDIR.ruby-pango?=	../../devel/ruby-pango

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-pango
