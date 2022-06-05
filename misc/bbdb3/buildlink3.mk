# $NetBSD: buildlink3.mk,v 1.2 2022/06/05 02:33:28 mef Exp $

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "emacs"

BUILDLINK_TREE+=	bbdb3

.  if !defined(BBDB3_BUILDLINK3_MK)
BBDB3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bbdb3+=	${EMACS_PKGNAME_PREFIX}bbdb3>=3.2
BUILDLINK_PKGSRCDIR.bbdb3?=	../../misc/bbdb3

BUILDLINK_CONTENTS_FILTER.bbdb3=	${EGREP} '.*\.el$$|.*\.elc$$'

.  else

# XEmacs has bbdb in xemacs-packages
EMACS_MODULES+=		base

.  endif # BBDB3_BUILDLINK3_MK
.endif # EMACS_FLAVOR

BUILDLINK_TREE+=	-bbdb3
