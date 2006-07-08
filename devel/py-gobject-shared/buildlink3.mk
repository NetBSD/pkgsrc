# $NetBSD: buildlink3.mk,v 1.4 2006/07/08 23:10:47 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_GOBJECT_SHARED_BUILDLINK3_MK:=	${PY_GOBJECT_SHARED_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-gobject-shared
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-gobject-shared}
BUILDLINK_PACKAGES+=	py-gobject-shared
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-gobject-shared

.if ${PY_GOBJECT_SHARED_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.py-gobject-shared+=	py-gobject-shared>=2.10.1
BUILDLINK_PKGSRCDIR.py-gobject-shared?=		../../devel/py-gobject-shared
BUILDLINK_DEPMETHOD.py-gobject-shared?=		build
.endif	# PY_GOBJECT_SHARED_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
