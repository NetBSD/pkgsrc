# $NetBSD: buildlink3.mk,v 1.6 2022/08/11 05:08:47 gutteridge Exp $

BUILDLINK_TREE+=	ruby-gdk3

.if !defined(RUBY_GDK3_BUILDLINK3_MK)
RUBY_GDK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gtk3>=3.3.8
BUILDLINK_ABI_DEPENDS.ruby-gdk3+=	${RUBY_PKGPREFIX}-gdk3>=3.5.1nb1
BUILDLINK_PKGSRCDIR.ruby-gdk3?=		../../graphics/ruby-gdk3

.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GDK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gdk3
