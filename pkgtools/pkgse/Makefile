# $NetBSD: Makefile,v 1.15 2016/07/09 06:38:49 wiz Exp $
#

DISTNAME=	pkgse-0.3
PKGREVISION=	6
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wp/
COMMENT=	Fetch informations about a NetBSD package from pkgsrc.netbsd.se

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

NO_BUILD=	yes
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin
REPLACE_PERL=	pkgse

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgse ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
