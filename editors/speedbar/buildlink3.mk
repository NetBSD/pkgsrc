# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:11 rillig Exp $
#

BUILDLINK_TREE+=	speedbar

.if !defined(SPEEDBAR_BUILDLINK3_MK)
SPEEDBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.speedbar+=	${EMACS_PKGNAME_PREFIX}speedbar>=0.14rc0
BUILDLINK_PKGSRCDIR.speedbar?=		../../editors/speedbar

BUILDLINK_CONTENTS_FILTER.speedbar=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # SPEEDBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-speedbar
