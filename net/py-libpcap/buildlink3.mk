# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/08/10 13:51:01 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYLIBPCAP_BUILDLINK3_MK:=	${PYLIBPCAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pylibpcap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npylibpcap}
BUILDLINK_PACKAGES+=	pylibpcap

.if !empty(PYLIBPCAP_BUILDLINK3_MK:M+)

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pylibpcap+=	${PYPKGPREFIX}-libpcap>=0.5.0
BUILDLINK_PKGSRCDIR.pylibpcap?=	../../net/py-libpcap

.endif	# PYLIBPCAP_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
