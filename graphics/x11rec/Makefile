# $NetBSD: Makefile,v 1.3 2006/01/24 07:32:17 wiz Exp $
#

DISTNAME=	x11rec-0.3
PKGREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://namazu.org/~satoru/x11rec/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://namazu.org/~satoru/x11rec/
COMMENT=	Very ad hoc X11 recorder which create a movie

DEPENDS+=	gifsicle-[0-9]*:../../graphics/gifsicle

NO_BUILD=	yes
REPLACE_RUBY=   x11rec

INSTALLATION_DIRS=      share/doc/html/x11rec

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/x11rec ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/x11rec-en.html \
		${PREFIX}/share/doc/html/x11rec/index.html.en
	${INSTALL_DATA} ${WRKSRC}/x11rec-ja.html \
		${PREFIX}/share/doc/html/x11rec/index.html.ja

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/ruby/modules.mk"

SUBST_CLASSES+=         toolpath
SUBST_STAGE.toolpath=   pre-configure
SUBST_FILES.toolpath=   x11rec
SUBST_SED.toolpath=     -e "s|@xwininfo@|${X11BASE}/bin/xwininfo|" \
			-e "s|@xwd@|${X11BASE}/bin/xwd|" \
			-e "s|@convert@|${BUILDLINK_PREFIX.ImageMagick}/bin/convert|" \
			-e "s|@gifsicle@|${PREFIX}/bin/gifsicle|"
SUBST_MESSAGE.toolpath=	"Fixing paths."

.include "../../mk/bsd.pkg.mk"
