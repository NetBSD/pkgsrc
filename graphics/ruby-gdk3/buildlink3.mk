# $NetBSD: buildlink3.mk,v 1.14 2023/08/12 08:37:20 tsutsui Exp $

BUILDLINK_TREE+=	ruby-gdk3

.if !defined(RUBY_GDK3_BUILDLINK3_MK)
RUBY_GDK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gdk3>=4.1.9
BUILDLINK_ABI_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gdk3>=4.1.9
BUILDLINK_PKGSRCDIR.ruby-gdk3?=		../../graphics/ruby-gdk3

.include "../../devel/ruby-pango/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GDK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gdk3
