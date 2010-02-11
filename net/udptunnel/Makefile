# $NetBSD: Makefile,v 1.7 2010/02/11 23:07:16 joerg Exp $
#

DISTNAME=	udptunnel-1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/lennox/udptunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www1.cs.columbia.edu/~lennox/udptunnel/
COMMENT=	Tunnel UDP packets over a TCP connection

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	bin share/doc/html

post-install:
	${INSTALL_DATA} ${WRKSRC}/udptunnel.html ${DESTDIR}${PREFIX}/share/doc/html/

.include "../../mk/bsd.pkg.mk"
