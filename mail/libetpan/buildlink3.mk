# $NetBSD: buildlink3.mk,v 1.19 2009/03/20 19:24:55 joerg Exp $

BUILDLINK_TREE+=	libetpan

.if !defined(LIBETPAN_BUILDLINK3_MK)
LIBETPAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libetpan+=	libetpan>=0.38nb1
BUILDLINK_ABI_DEPENDS.libetpan?=	libetpan>=0.52nb4
BUILDLINK_ABI_DEPENDS.libetpan?=	libetpan>=0.56
BUILDLINK_PKGSRCDIR.libetpan?=	../../mail/libetpan

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBETPAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libetpan
