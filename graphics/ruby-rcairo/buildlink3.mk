# $NetBSD: buildlink3.mk,v 1.15 2012/09/10 09:22:41 obache Exp $

BUILDLINK_TREE+=	ruby-rcairo

.if !defined(RUBY_RCAIRO_BUILDLINK3_MK)
RUBY_RCAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-rcairo+=	${RUBY_PKGPREFIX}-rcairo>=1.6.0
BUILDLINK_ABI_DEPENDS.ruby-rcairo+=	${RUBY_PKGPREFIX}-rcairo>=1.10.2nb1
BUILDLINK_PKGSRCDIR.ruby-rcairo?=	../../graphics/ruby-rcairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # RUBY_RCAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-rcairo
