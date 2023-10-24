# $NetBSD: buildlink3.mk,v 1.14 2023/10/24 22:09:39 wiz Exp $
#

BUILDLINK_TREE+=	qore

.if !defined(QORE_BUILDLINK3_MK)
QORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore+=	qore>=1.2 # API version 1.2
BUILDLINK_ABI_DEPENDS.qore?=	qore>=1.19.1nb1
BUILDLINK_PKGSRCDIR.qore?=	../../lang/qore

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# QORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore
