# $NetBSD: Makefile,v 1.6 2006/10/28 21:29:47 wiz Exp $
#

DISTNAME=	pkgse-0.3
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wp/
COMMENT=	Fetch informations about a NetBSD package from pkgsrc.netbsd.se

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pkgse ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
