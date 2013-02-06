# $NetBSD: buildlink3.mk,v 1.7 2013/02/06 23:21:02 jperkin Exp $

BUILDLINK_TREE+=	py-SSLCrypto

.if !defined(PY_SSLCRYPTO_BUILDLINK3_MK)
PY_SSLCRYPTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-SSLCrypto+=	${PYPKGPREFIX}-SSLCrypto>=0.1.1
BUILDLINK_ABI_DEPENDS.py-SSLCrypto+=	py27-SSLCrypto>=0.1.1nb4
BUILDLINK_PKGSRCDIR.py-SSLCrypto?=	../../security/py-SSLCrypto

#.include "../../security/openssl/buildlink3.mk"
.endif # PY_SSLCRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-SSLCrypto
