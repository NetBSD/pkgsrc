# $NetBSD: buildlink3.mk,v 1.3 2018/05/03 12:04:02 tsutsui Exp $

BUILDLINK_TREE+=	ruby-gnome2-gobject-introspection

.if !defined(RUBY_GNOME2_GOBJECT_INTROSPECTION_BUILDLINK3_MK)
RUBY_GNOME2_GOBJECT_INTROSPECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-gobject-introspection+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=1.2.0
BUILDLINK_ABI_DEPENDS.ruby-gnome2-gobject-introspection+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=3.2.5
BUILDLINK_PKGSRCDIR.ruby-gnome2-gobject-introspection?=		../../devel/ruby-gnome2-gobject-introspection

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GNOME2_GOBJECT_INTROSPECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-gobject-introspection
