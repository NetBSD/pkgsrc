# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:45 joerg Exp $

BUILDLINK_TREE+=	${RUBY_PKGPREFIX}-rcairo

.if !defined(RUBY_RCAIRO_BUILDLINK3_MK)
RUBY_RCAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby18-rcairo+=	${RUBY_PKGPREFIX}-rcairo>=1.6.0
BUILDLINK_PKGSRCDIR.ruby18-rcairo?=	../../graphics/ruby-rcairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # RUBY_RCAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-${RUBY_PKGPREFIX}-rcairo
