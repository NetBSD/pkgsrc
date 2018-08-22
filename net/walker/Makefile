# $NetBSD: Makefile,v 1.9 2018/08/22 09:46:08 wiz Exp $
#

DISTNAME=	walker-3.8
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://josefsson.org/walker/releases/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://josefsson.org/walker/
COMMENT=	Retrieve a DNS zone using NXT/NSEC traversal

DEPENDS+=	p5-Net-DNS>=0.50:../../net/p5-Net-DNS
DEPENDS+=	p5-Net-DNS-SEC>=0.12:../../security/p5-Net-DNS-SEC

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 bin
NO_BUILD=	yes
REPLACE_PERL=	walker
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run

do-install:
	${INSTALL} ${WRKSRC}/walker ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/walker.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
