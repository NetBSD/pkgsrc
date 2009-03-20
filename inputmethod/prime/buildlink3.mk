# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:47 joerg Exp $

BUILDLINK_TREE+=	prime

.if !defined(PRIME_BUILDLINK3_MK)
PRIME_BUILDLINK3_MK:=

.include "../../lang/ruby/rubyversion.mk"
BUILDLINK_API_DEPENDS.prime+=	${RUBY_PKGPREFIX}-prime>=1.0.0.1
BUILDLINK_PKGSRCDIR.prime?=	../../inputmethod/prime
.endif # PRIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-prime
