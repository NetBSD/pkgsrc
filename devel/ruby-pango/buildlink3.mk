# $NetBSD: buildlink3.mk,v 1.3 2020/03/10 22:08:46 wiz Exp $

BUILDLINK_TREE+=	ruby-pango

.if !defined(RUBY_PANGO_BUILDLINK3_MK)
RUBY_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=3.3.8
BUILDLINK_ABI_DEPENDS.ruby-pango+=	${RUBY_PKGPREFIX}-pango>=3.4.1nb2
BUILDLINK_PKGSRCDIR.ruby-pango?=	../../devel/ruby-pango

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-pango
