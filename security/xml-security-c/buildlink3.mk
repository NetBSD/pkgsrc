# $NetBSD: buildlink3.mk,v 1.7 2013/09/10 11:42:52 obache Exp $

BUILDLINK_TREE+=	xml-security-c

.if !defined(XML_SECURITY_C_BUILDLINK3_MK)
XML_SECURITY_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xml-security-c+=	xml-security-c>=1.4.0
BUILDLINK_ABI_DEPENDS.xml-security-c+=	xml-security-c>=1.7.0
BUILDLINK_PKGSRCDIR.xml-security-c?=	../../security/xml-security-c

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.endif # XML_SECURITY_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xml-security-c
