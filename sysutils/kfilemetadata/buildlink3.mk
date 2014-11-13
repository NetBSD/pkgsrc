# $NetBSD: buildlink3.mk,v 1.1 2014/11/13 11:05:43 markd Exp $

BUILDLINK_TREE+=	kfilemetadata

.if !defined(KFILEMETADATA_BUILDLINK3_MK)
KFILEMETADATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kfilemetadata+=	kfilemetadata>=4.14.3
BUILDLINK_PKGSRCDIR.kfilemetadata?=	../../sysutils/kfilemetadata

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../audio/taglib/buildlink3.mk"
#.include "../../graphics/exiv2/buildlink3.mk"
#.include "../../graphics/kdegraphics-mobipocket/buildlink3.mk"
#.include "../../multimedia/ffmpeg2/buildlink3.mk"
#.include "../../print/poppler-qt4/buildlink3.mk"
#.include "../../textproc/ebook-tools/buildlink3.mk"
#.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# KFILEMETADATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kfilemetadata
