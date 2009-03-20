# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:00 joerg Exp $
#

BUILDLINK_TREE+=	lookup

.if !defined(LOOKUP_BUILDLINK3_MK)
LOOKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lookup+=	${EMACS_PKGNAME_PREFIX}lookup>=1.4
BUILDLINK_PKGSRCDIR.lookup?=	../../misc/lookup

BUILDLINK_CONTENTS_FILTER.lookup=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # LOOKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-lookup
