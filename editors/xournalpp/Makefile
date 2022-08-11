# $NetBSD: Makefile,v 1.41 2022/08/11 05:08:17 gutteridge Exp $

DISTNAME=	xournalpp-1.1.1
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=xournalpp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xournalpp/xournalpp
COMMENT=	Take notes, sketch and annotate PDFs
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++

BUILD_TARGET=	translations xournalpp

# C++17, std::filesystem
GCC_REQD+=	8

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099915
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.endif

.include "../../archivers/libarchive/buildlink3.mk"

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-standalone-[0-9]*:../../print/tex-standalone

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 || ${TRUE}

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
