# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:48 joerg Exp $
#

BUILDLINK_TREE+=	eieio

.if !defined(EIEIO_BUILDLINK3_MK)
EIEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eieio+=	${EMACS_PKGNAME_PREFIX}eieio>=0.17
BUILDLINK_PKGSRCDIR.eieio?=	../../lang/eieio

BUILDLINK_CONTENTS_FILTER.eieio=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # EIEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-eieio
