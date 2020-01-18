# $NetBSD: buildlink3.mk,v 1.10 2020/01/18 21:48:25 jperkin Exp $

BUILDLINK_TREE+=	xml-security-c

.if !defined(XML_SECURITY_C_BUILDLINK3_MK)
XML_SECURITY_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xml-security-c+=	xml-security-c>=1.4.0
BUILDLINK_ABI_DEPENDS.xml-security-c+=	xml-security-c>=2.0.2nb1
BUILDLINK_PKGSRCDIR.xml-security-c?=	../../security/xml-security-c

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.endif # XML_SECURITY_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xml-security-c
