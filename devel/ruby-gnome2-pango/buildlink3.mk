# $NetBSD: buildlink3.mk,v 1.32 2013/06/06 12:53:48 wiz Exp $

BUILDLINK_TREE+=	ruby-gnome2-pango

.if !defined(RUBY_GNOME2_PANGO_BUILDLINK3_MK)
RUBY_GNOME2_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-pango+= ${RUBY_PKGPREFIX}-gnome2-pango>=0.16.0
BUILDLINK_ABI_DEPENDS.ruby-gnome2-pango+= ${RUBY_PKGPREFIX}-gnome2-pango>=2.0.0nb3
BUILDLINK_PKGSRCDIR.ruby-gnome2-pango?=	../../devel/ruby-gnome2-pango

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GNOME2_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-pango
