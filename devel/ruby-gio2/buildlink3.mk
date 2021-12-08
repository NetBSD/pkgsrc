# $NetBSD: buildlink3.mk,v 1.3 2021/12/08 16:02:03 adam Exp $

BUILDLINK_TREE+=	ruby-gio2

.if !defined(RUBY_GIO2_BUILDLINK3_MK)
RUBY_GIO2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gio2+=	${RUBY_PKGPREFIX}-gio2>=3.3.8
BUILDLINK_ABI_DEPENDS.ruby-gio2+=	${RUBY_PKGPREFIX}-gio2>=3.4.9
BUILDLINK_PKGSRCDIR.ruby-gio2?=		../../devel/ruby-gio2

.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GIO2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gio2
