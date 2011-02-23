# $NetBSD: buildlink3.mk,v 1.14 2011/02/23 10:32:29 adam Exp $

BUILDLINK_TREE+=	bdb-xml

.if !defined(BDB_XML_BUILDLINK3_MK)
BDB_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bdb-xml+=		bdb-xml>=2.5.16
BUILDLINK_ABI_DEPENDS.bdb-xml+=		bdb-xml>=2.5.16
BUILDLINK_PKGSRCDIR.bdb-xml?=		../../databases/bdb-xml

BDB_ACCEPTED=	db4 db5
.include "../../mk/bdb.buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../textproc/xqilla/buildlink3.mk"
.endif # BDB_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-bdb-xml
