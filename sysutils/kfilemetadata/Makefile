# $NetBSD: Makefile,v 1.13 2016/01/10 19:12:13 markd Exp $

DISTNAME=	kfilemetadata-${_KDE_VERSION}
PKGREVISION=	12
CATEGORIES=	sysutils
COMMENT=	Library for extracting file metadata
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/kdegraphics-mobipocket/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
