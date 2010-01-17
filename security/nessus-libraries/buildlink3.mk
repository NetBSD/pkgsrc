# $NetBSD: buildlink3.mk,v 1.16 2010/01/17 12:02:41 wiz Exp $

BUILDLINK_TREE+=	nessus-libraries

.if !defined(NESSUS_LIBRARIES_BUILDLINK3_MK)
NESSUS_LIBRARIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nessus-libraries+=	nessus-libraries>=2.2.11
BUILDLINK_ABI_DEPENDS.nessus-libraries?=	nessus-libraries>=2.2.11nb2
BUILDLINK_PKGSRCDIR.nessus-libraries?=	../../security/nessus-libraries

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # NESSUS_LIBRARIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-nessus-libraries
