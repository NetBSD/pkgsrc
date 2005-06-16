# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:41 jlam Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/
COMMENT=		Tesla coil design program

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
