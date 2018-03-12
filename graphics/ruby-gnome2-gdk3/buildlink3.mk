# $NetBSD: buildlink3.mk,v 1.18 2018/03/12 11:15:37 wiz Exp $

BUILDLINK_TREE+=	ruby-gnome2-gdk3

.if !defined(RUBY_GNOME2_GDK3_BUILDLINK3_MK)
RUBY_GNOME2_GDK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-gdk3+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=1.2
BUILDLINK_ABI_DEPENDS.ruby-gnome2-gdk3+=	ruby24-gnome2-gdk3>=3.2.1nb2
BUILDLINK_PKGSRCDIR.ruby-gnome2-gdk3?=		../../graphics/ruby-gnome2-gdk3

.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GNOME2_GDK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-gdk3
