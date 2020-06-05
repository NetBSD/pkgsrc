# $NetBSD: Makefile,v 1.56 2020/06/05 12:49:16 jperkin Exp $

DISTNAME=	kfilemetadata-${_KDE_VERSION}
PKGREVISION=	54
CATEGORIES=	sysutils
COMMENT=	Library for extracting file metadata
LICENSE=	gnu-gpl-v3

# breaks with newer exiv2 versions
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Exiv2=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_QMobipocket=TRUE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/taglib/buildlink3.mk"
#.include "../../graphics/kdegraphics-mobipocket/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
#.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
