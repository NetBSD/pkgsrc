# $NetBSD: buildlink3.mk,v 1.5 2022/12/08 15:22:01 tsutsui Exp $

BUILDLINK_TREE+=	ruby-glib2

.if !defined(RUBY_GLIB2_BUILDLINK3_MK)
RUBY_GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-glib2+=	${RUBY_PKGPREFIX}-glib2>=4.0.3
BUILDLINK_ABI_DEPENDS.ruby-glib2+=	${RUBY_PKGPREFIX}-glib2>=4.0.3
BUILDLINK_PKGSRCDIR.ruby-glib2?=	../../devel/ruby-glib2

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-glib2
