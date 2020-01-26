# $NetBSD: Makefile,v 1.10 2020/01/26 17:30:48 rillig Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		https://www.nic.funet.fi/pub/sci/electrical/tesla/
COMMENT=		Tesla coil design program

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
