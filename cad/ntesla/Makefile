# $NetBSD: Makefile,v 1.6 2003/07/21 16:32:12 martti Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/
COMMENT=		Tesla coil design program

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
