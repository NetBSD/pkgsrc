# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:11 joerg Exp $

BUILDLINK_TREE+=	pylibpcap

.if !defined(PYLIBPCAP_BUILDLINK3_MK)
PYLIBPCAP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pylibpcap+=	${PYPKGPREFIX}-libpcap>=0.5.0
BUILDLINK_ABI_DEPENDS.pylibpcap?=	${PYPKGPREFIX}-libpcap>=0.5nb1
BUILDLINK_PKGSRCDIR.pylibpcap?=	../../net/py-libpcap
.endif # PYLIBPCAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylibpcap
