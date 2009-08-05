# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/05 10:32:54 minskim Exp $
#

BUILDLINK_TREE+=	emacs-nox11

.if !defined(EMACS_NOX11_BUILDLINK3_MK)
EMACS_NOX11_BUILDLINK3_MK:=

.include "../../editors/emacs/modules.mk"
BUILDLINK_API_DEPENDS.emacs-nox11+=	${_EMACS_REQD}
BUILDLINK_PKGSRCDIR.emacs-nox11?=	${_EMACS_PKGDIR}

BUILDLINK_CONTENTS_FILTER.emacs-nox11=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # EMACS_NOX11_BUILDLINK3_MK

BUILDLINK_TREE+=	-emacs-nox11
