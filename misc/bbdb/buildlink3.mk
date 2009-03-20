# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:00 joerg Exp $
#

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "emacs"

BUILDLINK_TREE+=	bbdb

.if !defined(BBDB_BUILDLINK3_MK)
BBDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bbdb+=	${EMACS_PKGNAME_PREFIX}bbdb>=2
BUILDLINK_PKGSRCDIR.bbdb?=	../../misc/bbdb

BUILDLINK_CONTENTS_FILTER.bbdb=	${EGREP} '.*\.el$$|.*\.elc$$'

.else

# XEmacs has bbdb in xemacs-packages
EMACS_MODULES+=		base

.endif
.endif # BBDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-bbdb
