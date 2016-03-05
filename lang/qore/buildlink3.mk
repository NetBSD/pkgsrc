# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:50 jperkin Exp $
#

BUILDLINK_TREE+=	qore

.if !defined(QORE_BUILDLINK3_MK)
QORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore+=	qore>=0.8.11 # API version 0.18
BUILDLINK_ABI_DEPENDS.qore?=	qore>=0.8.11nb3
BUILDLINK_PKGSRCDIR.qore?=	../../lang/qore

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# QORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore
