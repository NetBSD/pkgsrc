# $NetBSD: Makefile,v 1.1 2015/03/01 09:59:45 wiz Exp $

DISTNAME=	sslsplit-0.4.10
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/rel/sslsplit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roe.ch/sslsplit/
COMMENT=	Transparent and scalable SSL/TLS interception
LICENSE=	2-clause-bsd

MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslsplit ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sslsplit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
