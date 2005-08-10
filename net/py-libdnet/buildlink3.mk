# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/08/10 13:52:52 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYLIBDNET_BUILDLINK3_MK:=	${PYLIBDNET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pylibdnet
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npylibdnet}
BUILDLINK_PACKAGES+=	pylibdnet

.if !empty(PYLIBDNET_BUILDLINK3_MK:M+)

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pylibdnet+=	${PYPKGPREFIX}-libdnet>=1.7
BUILDLINK_PKGSRCDIR.pylibdnet?=	../../net/py-libdnet
.endif	# PYLIBDNET_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
