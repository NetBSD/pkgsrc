# $NetBSD: Makefile,v 1.11 2025/09/21 21:22:38 wiz Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.nic.funet.fi/pub/sci/electrical/tesla/
COMMENT=		Tesla coil design program

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
