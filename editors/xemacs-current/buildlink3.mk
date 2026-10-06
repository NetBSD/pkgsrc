# $NetBSD: buildlink3.mk,v 1.5 2026/10/06 09:31:11 hauke Exp $
#

BUILDLINK_TREE+=	xemacs

.if !defined(XEMACS_BUILDLINK3_MK)
XEMACS_BUILDLINK3_MK:=

.include "../../editors/emacs/modules.mk"
BUILDLINK_API_DEPENDS.xemacs+=	${_EMACS_REQD}
BUILDLINK_ABI_DEPENDS.xemacs?=	xemacs>=21.5.37
BUILDLINK_PKGSRCDIR.xemacs?=	${_EMACS_PKGDIR}

BUILDLINK_CONTENTS_FILTER.xemacs=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # XEMACS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xemacs
