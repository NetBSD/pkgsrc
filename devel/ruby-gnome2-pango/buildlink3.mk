# $NetBSD: buildlink3.mk,v 1.42 2017/02/12 06:24:42 ryoon Exp $

BUILDLINK_TREE+=	ruby-gnome2-pango

.if !defined(RUBY_GNOME2_PANGO_BUILDLINK3_MK)
RUBY_GNOME2_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-pango+=${RUBY_PKGPREFIX}-gnome2-pango>=0.16.0
BUILDLINK_ABI_DEPENDS.ruby-gnome2-pango+=${RUBY_PKGPREFIX}-gnome2-pango>=3.1.1nb1
BUILDLINK_ABI_DEPENDS.ruby-gnome2-pango?=	ruby23-gnome2-pango>=3.1.1nb2
BUILDLINK_PKGSRCDIR.ruby-gnome2-pango?=	../../devel/ruby-gnome2-pango

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GNOME2_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-pango
