# $NetBSD: buildlink3.mk,v 1.4 2020/08/17 20:17:32 leot Exp $

BUILDLINK_TREE+=	ruby-gdk3

.if !defined(RUBY_GDK3_BUILDLINK3_MK)
RUBY_GDK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gtk3>=3.3.8
BUILDLINK_ABI_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gdk3>=3.4.2nb1
BUILDLINK_PKGSRCDIR.ruby-gdk3?=		../../graphics/ruby-gdk3

.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GDK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gdk3
