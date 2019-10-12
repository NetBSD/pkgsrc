# $NetBSD: Makefile,v 1.9 2019/10/12 20:31:37 rillig Exp $
#

DISTNAME=	udptunnel-1.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/lennox/udptunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www1.cs.columbia.edu/~lennox/udptunnel/
COMMENT=	Tunnel UDP packets over a TCP connection

GNU_CONFIGURE=	yes
AUTO_MKDIRS=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/udptunnel.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
