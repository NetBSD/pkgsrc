# $NetBSD: Makefile,v 1.8 2012/10/23 17:19:15 asau Exp $
#

DISTNAME=	udptunnel-1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/lennox/udptunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www1.cs.columbia.edu/~lennox/udptunnel/
COMMENT=	Tunnel UDP packets over a TCP connection

GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	bin share/doc/html

post-install:
	${INSTALL_DATA} ${WRKSRC}/udptunnel.html ${DESTDIR}${PREFIX}/share/doc/html/

.include "../../mk/bsd.pkg.mk"
