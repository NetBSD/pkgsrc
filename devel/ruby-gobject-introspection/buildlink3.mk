# $NetBSD: buildlink3.mk,v 1.25 2026/09/02 19:01:44 wiz Exp $

BUILDLINK_TREE+=	ruby-gobject-introspection

.if !defined(RUBY_GOBJECT_INTROSPECTION_BUILDLINK3_MK)
RUBY_GOBJECT_INTROSPECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gobject-introspection+=	${RUBY_PKGPREFIX}-gobject-introspection>=4.3.7
BUILDLINK_ABI_DEPENDS.ruby-gobject-introspection+=	${RUBY_PKGPREFIX}-gobject-introspection>=4.3.7nb1
BUILDLINK_PKGSRCDIR.ruby-gobject-introspection?=	../../devel/ruby-gobject-introspection

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/ruby-glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GOBJECT_INTROSPECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gobject-introspection
