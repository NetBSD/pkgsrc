# $NetBSD: buildlink3.mk,v 1.9 2012/03/03 00:12:01 wiz Exp $

BUILDLINK_TREE+=	ruby-gnome2-glib

.if !defined(RUBY_GNOME2_GLIB_BUILDLINK3_MK)
RUBY_GNOME2_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=0.17.0
BUILDLINK_ABI_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=1.1.2nb2
BUILDLINK_PKGSRCDIR.ruby-gnome2-glib?=		../../devel/ruby-gnome2-glib

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GNOME2_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-glib
