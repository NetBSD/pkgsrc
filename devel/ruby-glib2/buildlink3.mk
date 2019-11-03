# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:00:23 rillig Exp $

BUILDLINK_TREE+=	ruby-glib2

.if !defined(RUBY_GLIB2_BUILDLINK3_MK)
RUBY_GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-glib2+=	${RUBY_PKGPREFIX}-glib2>=3.3.8
BUILDLINK_ABI_DEPENDS.ruby-glib2+=	${RUBY_PKGPREFIX}-glib2>=3.3.8
BUILDLINK_PKGSRCDIR.ruby-glib2?=	../../devel/ruby-glib2

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.endif # RUBY_GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-glib2
