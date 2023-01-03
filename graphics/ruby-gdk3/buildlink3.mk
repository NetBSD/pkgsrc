# $NetBSD: buildlink3.mk,v 1.9 2023/01/03 17:36:27 wiz Exp $

BUILDLINK_TREE+=	ruby-gdk3

.if !defined(RUBY_GDK3_BUILDLINK3_MK)
RUBY_GDK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gdk3>=4.0.3
BUILDLINK_ABI_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gdk3>=4.0.5nb1
BUILDLINK_PKGSRCDIR.ruby-gdk3?=		../../graphics/ruby-gdk3

.include "../../devel/ruby-pango/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GDK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gdk3
