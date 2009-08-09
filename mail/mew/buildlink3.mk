# $NetBSD: buildlink3.mk,v 1.3 2009/08/09 12:01:18 minskim Exp $
#

BUILDLINK_TREE+=	mew

.if !defined(MEW_BUILDLINK3_MK)
MEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mew+=	${EMACS_PKGNAME_PREFIX}mew>=6
BUILDLINK_PKGSRCDIR.mew?=	../../mail/mew

BUILDLINK_CONTENTS_FILTER.mew=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # MEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-mew
