# $NetBSD: buildlink3.mk,v 1.4 2022/12/08 15:22:00 tsutsui Exp $

BUILDLINK_TREE+=	ruby-gio2

.if !defined(RUBY_GIO2_BUILDLINK3_MK)
RUBY_GIO2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gio2+=	${RUBY_PKGPREFIX}-gio2>=4.0.3
BUILDLINK_ABI_DEPENDS.ruby-gio2+=	${RUBY_PKGPREFIX}-gio2>=4.0.3
BUILDLINK_PKGSRCDIR.ruby-gio2?=		../../devel/ruby-gio2

.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GIO2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gio2
