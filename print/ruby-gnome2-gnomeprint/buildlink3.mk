# $NetBSD: buildlink3.mk,v 1.2 2009/01/19 04:12:55 obache Exp $

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
RUBY_GNOME2_GNOMEPRINT_BUILDLINK3_MK:=	${RUBY_GNOME2_GNOMEPRINT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ruby-gnome2-gnomeprint
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nruby-gnome2-gnomeprint}
BUILDLINK_PACKAGES+=	ruby-gnome2-gnomeprint
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ruby-gnome2-gnomeprint

.if ${RUBY_GNOME2_GNOMEPRINT_BUILDLINK3_MK} == "+"
.include "../../lang/ruby/rubyversion.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-gnomeprint+=	${RUBY_PKGPREFIX}-gnome2-gnomeprint>=0.17.0
BUILDLINK_PKGSRCDIR.ruby-gnome2-gnomeprint?=	../../print/ruby-gnome2-gnomeprint
.endif	# RUBY_GNOME2_GNOMEPRINT_BUILDLINK3_MK

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH:S/+$//}
