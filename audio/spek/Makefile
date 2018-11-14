# $NetBSD: Makefile,v 1.19 2018/11/14 22:21:06 kleink Exp $

DISTNAME=	spek-0.8.2
PKGREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexkay/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spek.cc/
COMMENT=	Acoustic Spectrum Analyzer
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake intltool xgettext msgmerge msgfmt pkg-config
MAKE_FLAGS+=	DATADIRNAME=${PKGLOCALEDIR}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
