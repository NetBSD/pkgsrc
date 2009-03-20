# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:02 joerg Exp $
#

BUILDLINK_TREE+=	riece

.if !defined(RIECE_BUILDLINK3_MK)
RIECE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.riece+=	${EMACS_PKGNAME_PREFIX}riece>=4
BUILDLINK_PKGSRCDIR.riece?=	../../chat/riece

BUILDLINK_CONTENTS_FILTER.riece=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # RIECE_BUILDLINK3_MK

BUILDLINK_TREE+=	-riece
