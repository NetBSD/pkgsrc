# $NetBSD: Makefile,v 1.8 2005/01/26 17:42:53 ben Exp $

DISTNAME=	compface-1.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://freshmeat.net/redir/compface/1439/url_tgz/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://freshmeat.net/projects/compface/
COMMENT=	48x48x1 image compression and decompression (X-face utility)

CONFLICTS=	faces-[0-9]*

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		perlpath
SUBST_MESSAGE.perlpath=	"Configuring Perl path."
SUBST_STAGE.perlpath=	pre-configure
SUBST_FILES.perlpath=	xbm2xface.pl
SUBST_SED.perlpath=	-e 's|||' -e 's|/usr/bin|${PREFIX}/bin|g'

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbm2xface.pl ${PREFIX}/bin

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
