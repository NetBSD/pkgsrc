# $NetBSD: buildlink3.mk,v 1.1 2013/02/07 13:41:55 obache Exp $

BUILDLINK_TREE+=	ruby-gnome2-gio

.if !defined(RUBY_GNOME2_GIO_BUILDLINK3_MK)
RUBY_GNOME2_GIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-gio+=	${RUBY_PKGPREFIX}-gnome2-gio>=1.2.0
BUILDLINK_PKGSRCDIR.ruby-gnome2-gio?=		../../devel/ruby-gnome2-gio

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GNOME2_GIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-gio
