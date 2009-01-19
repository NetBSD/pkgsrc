# $NetBSD: buildlink3.mk,v 1.10 2009/01/19 04:07:54 obache Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
RUBY_GNOME2_PANGO_BUILDLINK3_MK:=	${RUBY_GNOME2_PANGO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ruby-gnome2-pango
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nruby-gnome2-pango}
BUILDLINK_PACKAGES+=	ruby-gnome2-pango
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ruby-gnome2-pango

.if !empty(RUBY_GNOME2_PANGO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ruby-gnome2-pango+=	${RUBY_PKGPREFIX}-gnome2-pango>=0.16.0
BUILDLINK_PKGSRCDIR.ruby-gnome2-pango?=	../../devel/ruby-gnome2-pango
.endif	# RUBY_GNOME2_PANGO_BUILDLINK3_MK

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
