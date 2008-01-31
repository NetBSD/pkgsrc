# $NetBSD: Makefile,v 1.7 2008/01/31 19:01:05 rillig Exp $
#

DISTNAME=	pkgse-0.3
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wp/
COMMENT=	Fetch informations about a NetBSD package from pkgsrc.netbsd.se

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=	yes
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin
REPLACE_PERL=	pkgse

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgse ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
