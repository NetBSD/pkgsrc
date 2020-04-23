# $NetBSD: Makefile,v 1.23 2020/04/23 16:12:57 nia Exp $

DISTNAME=	spek-0.8.2
PKGREVISION=	18
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexkay/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spek.cc/
COMMENT=	Acoustic Spectrum Analyzer
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake intltool xgettext msgmerge msgfmt pkg-config
MAKE_FLAGS+=	DATADIRNAME=${PKGLOCALEDIR}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
