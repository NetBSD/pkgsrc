# $NetBSD: buildlink3.mk,v 1.6 2020/06/02 08:22:57 adam Exp $

BUILDLINK_TREE+=	hfstospell

.if !defined(HFSTOSPELL_BUILDLINK3_MK)
HFSTOSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hfstospell+=	hfstospell>=0.5.1
BUILDLINK_ABI_DEPENDS.hfstospell?=	hfstospell>=0.5.1nb5
BUILDLINK_PKGSRCDIR.hfstospell?=	../../textproc/hfstospell

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.endif	# HFSTOSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hfstospell
