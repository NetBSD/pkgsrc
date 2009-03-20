# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 17:30:11 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_GOBJECT_BUILDLINK3_MK:=	${PY_GOBJECT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pygobject
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npygobject}
BUILDLINK_PACKAGES+=	pygobject
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pygobject

.if !empty(PY_GOBJECT_BUILDLINK3_MK:M+)
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.10.1nb1
BUILDLINK_PKGSRCDIR.pygobject?=	../../devel/py-gobject
.endif	# PY_GOBJECT_BUILDLINK3_MK

.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
