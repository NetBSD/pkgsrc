# $NetBSD: buildlink3.mk,v 1.4 2011/04/14 18:23:40 hans Exp $
#

#
# Only for older GNU Emacs.  Emacs 22 or later doesn't need this because it
# incorporated Unicode support.
#

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} < 22

BUILDLINK_TREE+=	mule-ucs

.if !defined(MULE_UCS_BUILDLINK3_MK)
MULE_UCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mule-ucs+=	${EMACS_PKGNAME_PREFIX}Mule-UCS>=0.84
BUILDLINK_PKGSRCDIR.mule-ucs?=	../../editors/mule-ucs

BUILDLINK_CONTENTS_FILTER.mule-ucs=	${EGREP} '.*\.el$$|.*\.elc$$'

.endif # MULE_UCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mule-ucs
.endif
