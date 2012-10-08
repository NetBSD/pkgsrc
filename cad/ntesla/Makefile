# $NetBSD: Makefile,v 1.9 2012/10/08 13:25:14 asau Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/
COMMENT=		Tesla coil design program

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
