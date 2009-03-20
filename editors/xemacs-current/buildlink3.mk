# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:32 joerg Exp $
#

BUILDLINK_TREE+=	xemacs

.if !defined(XEMACS_BUILDLINK3_MK)
XEMACS_BUILDLINK3_MK:=

.include "../../editors/emacs/modules.mk"
BUILDLINK_API_DEPENDS.xemacs+=	${_EMACS_REQD}
BUILDLINK_PKGSRCDIR.xemacs?=	${_EMACS_PKGDIR}

BUILDLINK_CONTENTS_FILTER.xemacs=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # XEMACS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xemacs
