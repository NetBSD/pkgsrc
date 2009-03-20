# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:32 joerg Exp $
#

BUILDLINK_TREE+=	speedbar

.if !defined(SPEEDBAR_BUILDLINK3_MK)
SPEEDBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.speedbar+=	${EMACS_PKGNAME_PREFIX}speedbar>=0.14rc0
BUILDLINK_PKGSRCDIR.speedbar?=	../../editors/speedbar

BUILDLINK_CONTENTS_FILTER.speedbar=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # SPEEDBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-speedbar
