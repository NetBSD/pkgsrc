# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:00 rillig Exp $
#

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "emacs"

BUILDLINK_TREE+=	apel

.  if !defined(APEL_BUILDLINK3_MK)
APEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apel+=	${EMACS_PKGNAME_PREFIX}apel>=10
BUILDLINK_PKGSRCDIR.apel?=	../../devel/apel

BUILDLINK_CONTENTS_FILTER.apel=	${EGREP} '.*\.el$$|.*\.elc$$'

.  else

# XEmacs has apel in xemacs-packages
EMACS_MODULES+=		base

.  endif
.endif # APEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-apel
