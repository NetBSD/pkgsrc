# $NetBSD: Makefile,v 1.2 2004/07/19 23:17:16 xtraeme Exp $
#

DISTNAME=	pkgse-0.1
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Fetch informations about a NetBSD package on pkgsrc.netbsd.se

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_PERL5=	yes

INSTALLATION_DIRS=	bin

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pkgse ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
