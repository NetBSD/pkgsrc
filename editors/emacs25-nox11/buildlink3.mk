# $NetBSD: buildlink3.mk,v 1.1 2016/09/18 13:38:22 ryoon Exp $
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
