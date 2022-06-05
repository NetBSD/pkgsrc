# $NetBSD: buildlink3.mk,v 1.1 2022/06/05 02:27:31 mef Exp $
#

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "emacs"

BUILDLINK_TREE+=	bbdb2

.  if !defined(BBDB2_BUILDLINK3_MK)
BBDB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bbdb2+=	${EMACS_PKGNAME_PREFIX}bbdb2>=2
BUILDLINK_API_DEPENDS.bbdb2+=	${EMACS_PKGNAME_PREFIX}bbdb2<3
BUILDLINK_PKGSRCDIR.bbdb2?=	../../misc/bbdb2

BUILDLINK_CONTENTS_FILTER.bbdb2=	${EGREP} '.*\.el$$|.*\.elc$$'

BUILDLINK_TREE+=	-bbdb2

.  else
# XEmacs has bbdb in xemacs-packages
EMACS_MODULES+=		base
.  endif

.endif
