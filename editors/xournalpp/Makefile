# $NetBSD: Makefile,v 1.2 2019/10/19 12:46:05 nia Exp $

DISTNAME=	xournalpp-1.0.15
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=xournalpp/}
GITHUB_PROJECT=	xournalpp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xournalpp/xournalpp
COMMENT=	Take notes, sketch and annotate PDFs
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-standalone-[0-9]*:../../print/tex-standalone

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
