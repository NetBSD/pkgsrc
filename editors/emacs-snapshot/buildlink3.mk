# $NetBSD: buildlink3.mk,v 1.1 2009/06/05 21:18:02 minskim Exp $

BUILDLINK_TREE+=	emacs

.if !defined(EMACS_BUILDLINK3_MK)
EMACS_BUILDLINK3_MK:=

.include "../../editors/emacs/modules.mk"
BUILDLINK_API_DEPENDS.emacs+=	${_EMACS_REQD}
BUILDLINK_PKGSRCDIR.emacs?=	${_EMACS_PKGDIR}

BUILDLINK_CONTENTS_FILTER.emacs=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # EMACS_BUILDLINK3_MK

BUILDLINK_TREE+=	-emacs
