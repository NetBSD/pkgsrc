# $NetBSD: buildlink3.mk,v 1.16 2020/11/05 09:07:07 ryoon Exp $

BUILDLINK_TREE+=	xmlsec1

.if !defined(XMLSEC1_BUILDLINK3_MK)
XMLSEC1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlsec1+=	xmlsec1>=1.2.6nb6
BUILDLINK_ABI_DEPENDS.xmlsec1+=	xmlsec1>=1.2.25nb3
BUILDLINK_PKGSRCDIR.xmlsec1?=	../../security/xmlsec1
BUILDLINK_INCDIRS.xmlsec1+=	include/xmlsec1
BUILDLINK_CPPFLAGS.xmlsec1+=	-DXMLSEC_CRYPTO_OPENSSL
BUILDLINK_LIBS.xmlsec1+=	-lxmlsec1-openssl

.include "../../devel/libltdl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # XMLSEC1_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmlsec1
