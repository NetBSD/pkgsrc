# $NetBSD: buildlink3.mk,v 1.29 2020/06/02 08:22:33 adam Exp $

BUILDLINK_TREE+=	idzebra

.if !defined(IDZEBRA_BUILDLINK3_MK)
IDZEBRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.idzebra+=	idzebra>=2.0.47
BUILDLINK_ABI_DEPENDS.idzebra+=	idzebra>=2.0.62nb13
BUILDLINK_PKGSRCDIR.idzebra?=	../../databases/idzebra

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.endif	# IDZEBRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-idzebra
