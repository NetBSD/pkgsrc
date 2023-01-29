# $NetBSD: buildlink3.mk,v 1.7 2023/01/29 21:14:33 ryoon Exp $

BUILDLINK_TREE+=	ruby-pango

.if !defined(RUBY_PANGO_BUILDLINK3_MK)
RUBY_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=4.0.3
BUILDLINK_ABI_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=4.0.5nb1
BUILDLINK_PKGSRCDIR.ruby-pango?=	../../devel/ruby-pango

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-pango
