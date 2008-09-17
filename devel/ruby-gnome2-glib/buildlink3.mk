# $NetBSD: buildlink3.mk,v 1.1 2008/09/17 00:21:49 obache Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
RUBY_GNOME2_GLIB_BUILDLINK3_MK:=	${RUBY_GNOME2_GLIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ruby-gnome2-glib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nruby-gnome2-glib}
BUILDLINK_PACKAGES+=	ruby-gnome2-glib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ruby-gnome2-glib

.if ${RUBY_GNOME2_GLIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=0.17.0
BUILDLINK_PKGSRCDIR.ruby-gnome2-glib?=		../../devel/ruby-gnome2-glib
.endif	# RUBY_GNOME2_GLIB_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
