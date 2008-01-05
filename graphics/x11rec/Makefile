# $NetBSD: Makefile,v 1.13 2008/01/05 08:34:40 obache Exp $
#

DISTNAME=	x11rec-0.3
PKGREVISION=	5
CATEGORIES=	graphics ruby
MASTER_SITES=	http://0xcc.net/x11rec/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://0xcc.net/x11rec/
COMMENT=	Very ad hoc X11 recorder which create a movie

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	gifsicle-[0-9]*:../../graphics/gifsicle

NO_BUILD=	yes
REPLACE_RUBY=	x11rec

INSTALLATION_DIRS=	bin share/doc/html/x11rec

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/x11rec ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/x11rec-en.html \
		${DESTDIR}${PREFIX}/share/doc/html/x11rec/index.html.en
	${INSTALL_DATA} ${WRKSRC}/x11rec-ja.html \
		${DESTDIR}${PREFIX}/share/doc/html/x11rec/index.html.ja

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

SUBST_CLASSES+=		toolpath
SUBST_STAGE.toolpath=	pre-configure
SUBST_MESSAGE.toolpath=	Fixing paths.
SUBST_FILES.toolpath=	x11rec
SUBST_SED.toolpath=	-e "s|@xwininfo@|${X11BASE}/bin/xwininfo|"
SUBST_SED.toolpath+=	-e "s|@xwd@|${X11BASE}/bin/xwd|"
SUBST_SED.toolpath+=	-e "s|@convert@|${BUILDLINK_PREFIX.ImageMagick}/bin/convert|"
SUBST_SED.toolpath+=	-e "s|@gifsicle@|${PREFIX}/bin/gifsicle|"

.include "../../mk/bsd.pkg.mk"
