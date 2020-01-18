# $NetBSD: buildlink3.mk,v 1.6 2020/01/18 21:48:14 jperkin Exp $
#

BUILDLINK_TREE+=	qore

.if !defined(QORE_BUILDLINK3_MK)
QORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore+=	qore>=0.8.13.5 # API version 0.21
BUILDLINK_ABI_DEPENDS.qore?=	qore>=0.8.13.5nb1
BUILDLINK_PKGSRCDIR.qore?=	../../lang/qore

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# QORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore
