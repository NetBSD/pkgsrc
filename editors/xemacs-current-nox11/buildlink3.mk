# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:32 joerg Exp $
#

BUILDLINK_TREE+=	xemacs-nox11

.if !defined(XEMACS_NOX11_BUILDLINK3_MK)
XEMACS_NOX11_BUILDLINK3_MK:=

.include "../../editors/emacs/modules.mk"
BUILDLINK_API_DEPENDS.xemacs-nox11+=	${_EMACS_REQD}
BUILDLINK_PKGSRCDIR.xemacs-nox11?=	${_EMACS_PKGDIR}

BUILDLINK_CONTENTS_FILTER.xemacs-nox11=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # XEMACS_NOX11_BUILDLINK3_MK

BUILDLINK_TREE+=	-xemacs-nox11
