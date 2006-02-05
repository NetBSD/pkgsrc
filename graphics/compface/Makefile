# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:28 joerg Exp $

DISTNAME=	compface-1.5.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://freshmeat.net/redir/compface/1439/url_tgz/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://freshmeat.net/projects/compface/
COMMENT=	48x48x1 image compression and decompression (X-face utility)

CONFLICTS=	faces-[0-9]*

USE_TOOLS+=		autoconf gmake
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		perlpath
SUBST_MESSAGE.perlpath=	"Configuring Perl path."
SUBST_STAGE.perlpath=	pre-configure
SUBST_FILES.perlpath=	xbm2xface.pl
SUBST_SED.perlpath=	-e 's|||' -e 's|/usr/bin|${PREFIX}/bin|g'

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbm2xface.pl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
