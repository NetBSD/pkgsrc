# $NetBSD: buildlink3.mk,v 1.4 2018/01/28 16:24:11 wiz Exp $
#

BUILDLINK_TREE+=	qore

.if !defined(QORE_BUILDLINK3_MK)
QORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore+=	qore>=0.8.12 # API version 0.19
BUILDLINK_ABI_DEPENDS.qore?=	qore>=0.8.13nb1
BUILDLINK_PKGSRCDIR.qore?=	../../lang/qore

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# QORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore
