# $NetBSD: buildlink3.mk,v 1.2 2008/10/11 09:31:57 uebayasi Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BBDB_BUILDLINK3_MK:=	${BBDB_BUILDLINK3_MK}+

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "emacs"

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	bbdb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nbbdb}
BUILDLINK_PACKAGES+=	bbdb
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}bbdb

.if ${BBDB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.bbdb+=	${EMACS_PKGNAME_PREFIX}bbdb>=2
BUILDLINK_PKGSRCDIR.bbdb?=	../../misc/bbdb
.endif	# BBDB_BUILDLINK3_MK

BUILDLINK_CONTENTS_FILTER.bbdb=	${EGREP} '.*\.el$$|.*\.elc$$'

.else

# XEmacs has bbdb in xemacs-packages
EMACS_MODULES+=		base

.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
