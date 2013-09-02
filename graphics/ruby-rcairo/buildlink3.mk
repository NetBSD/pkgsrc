# $NetBSD: buildlink3.mk,v 1.20 2013/09/02 19:50:39 adam Exp $

BUILDLINK_TREE+=	ruby-rcairo

.if !defined(RUBY_RCAIRO_BUILDLINK3_MK)
RUBY_RCAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-rcairo+=	${RUBY_PKGPREFIX}-rcairo>=1.6.0
BUILDLINK_ABI_DEPENDS.ruby-rcairo+=	${RUBY_PKGPREFIX}-rcairo>=1.12.6nb1
BUILDLINK_PKGSRCDIR.ruby-rcairo?=	../../graphics/ruby-rcairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # RUBY_RCAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-rcairo
