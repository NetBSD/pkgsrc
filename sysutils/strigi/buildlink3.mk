# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:26 joerg Exp $

BUILDLINK_TREE+=	strigi

.if !defined(STRIGI_BUILDLINK3_MK)
STRIGI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.strigi+=	strigi>=0.6.2
BUILDLINK_PKGSRCDIR.strigi?=	../../sysutils/strigi

PRINT_PLIST_AWK+=	/^@dirrm lib\/strigi$$/ \
				{ print "@comment in strigi: " $$0; next; }

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # STRIGI_BUILDLINK3_MK

BUILDLINK_TREE+=	-strigi
