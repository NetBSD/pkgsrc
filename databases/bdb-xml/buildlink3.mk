# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:04 joerg Exp $

BUILDLINK_TREE+=	bdb-xml

.if !defined(BDB_XML_BUILDLINK3_MK)
BDB_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bdb-xml+=	bdb-xml>=1.2.1nb3
BUILDLINK_ABI_DEPENDS.bdb-xml?=	bdb-xml>=1.2.1nb8
BUILDLINK_PKGSRCDIR.bdb-xml?=	../../databases/bdb-xml

.include "../../databases/db46/buildlink3.mk"
.include "../../textproc/libpathan/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.endif # BDB_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-bdb-xml
