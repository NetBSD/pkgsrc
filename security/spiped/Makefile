# $NetBSD: Makefile,v 1.1 2014/04/18 21:31:26 wiz Exp $

DISTNAME=	spiped-1.3.1
CATEGORIES=	net security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tarsnap.com/spiped/
COMMENT=	Tool for creating symmetrically encrypted and authenticated pipes
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin

INSTALLATION_DIRS=	share/doc/spiped

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/spiped

.include "../../mk/bsd.pkg.mk"
