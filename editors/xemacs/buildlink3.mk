# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:33:49 wiz Exp $
#

BUILDLINK_TREE+=	xemacs

.if !defined(XEMACS_BUILDLINK3_MK)
XEMACS_BUILDLINK3_MK:=

.include "../../editors/emacs/modules.mk"
BUILDLINK_API_DEPENDS.xemacs+=	${_EMACS_REQD}
BUILDLINK_ABI_DEPENDS.xemacs?=	xemacs>=21.4.24nb19
BUILDLINK_PKGSRCDIR.xemacs?=	${_EMACS_PKGDIR}

BUILDLINK_CONTENTS_FILTER.xemacs=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # XEMACS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xemacs
