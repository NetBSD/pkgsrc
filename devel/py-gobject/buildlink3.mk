# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/02/07 18:59:59 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_GOBJECT_BUILDLINK3_MK:=	${PY_GOBJECT_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pygobject
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npygobject}
BUILDLINK_PACKAGES+=	pygobject

.if !empty(PY_GOBJECT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.9.1
BUILDLINK_PKGSRCDIR.pygobject?=	../../devel/py-gobject
.endif	# PY_GOBJECT_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
