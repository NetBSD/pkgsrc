# $NetBSD: Makefile,v 1.3 2004/08/12 13:15:45 wiz Exp $
#

DISTNAME=	pkgse-0.2
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Fetch informations about a NetBSD package from pkgsrc.netbsd.se

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_PERL5=	yes

INSTALLATION_DIRS=	bin

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pkgse ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
