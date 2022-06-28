# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:35:27 wiz Exp $
#

BUILDLINK_TREE+=	auctex

.if !defined(AUCTEX_BUILDLINK3_MK)
AUCTEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.auctex+=	${EMACS_PKGNAME_PREFIX}auctex>=11
BUILDLINK_ABI_DEPENDS.auctex?=	auctex>=11.92nb15
BUILDLINK_PKGSRCDIR.auctex?=	../../print/auctex

BUILDLINK_CONTENTS_FILTER.auctex=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # AUCTEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-auctex
