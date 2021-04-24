# $NetBSD: Makefile,v 1.10 2021/04/24 10:37:33 wiz Exp $

DISTNAME=	udptunnel-1.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www1.cs.columbia.edu/~lennox/udptunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www1.cs.columbia.edu/~lennox/udptunnel/
COMMENT=	Tunnel UDP packets over a TCP connection

GNU_CONFIGURE=	yes
AUTO_MKDIRS=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/udptunnel.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
