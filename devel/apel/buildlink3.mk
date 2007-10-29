# $NetBSD: buildlink3.mk,v 1.1 2007/10/29 12:41:16 uebayasi Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APEL_BUILDLINK3_MK:=	${APEL_BUILDLINK3_MK}+

.include "../../mk/emacs.mk"
.if ${EMACS_FLAVOR} == "emacs"

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	apel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napel}
BUILDLINK_PACKAGES+=	apel
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}apel

.if ${APEL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.apel+=	${EMACS_PKGNAME_PREFIX}apel>=10
BUILDLINK_PKGSRCDIR.apel?=	../../devel/apel
.endif	# APEL_BUILDLINK3_MK

BUILDLINK_CONTENTS_FILTER.apel=	${EGREP} '.*\.el$$|.*\.elc$$'

.else

# XEmacs has apel in xemacs-packages
EMACS_MODULES+=		base

.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
