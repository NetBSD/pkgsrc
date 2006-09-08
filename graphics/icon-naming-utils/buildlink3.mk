# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/09/08 16:29:02 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
ICON_NAMING_UTILS_BUILDLINK3_MK:=	${ICON_NAMING_UTILS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	icon-naming-utils
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nicon-naming-utils}
BUILDLINK_PACKAGES+=	icon-naming-utils
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}icon-naming-utils

.if ${ICON_NAMING_UTILS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.1
BUILDLINK_DEPMETHOD.icon-naming-utils?=		build
BUILDLINK_PKGSRCDIR.icon-naming-utils?=		../../graphics/icon-naming-utils
.endif	# ICON_NAMING_UTILS_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
