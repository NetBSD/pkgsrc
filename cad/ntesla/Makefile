# $NetBSD: Makefile,v 1.4 2001/02/16 13:46:26 wiz Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/
COMMENT=		tesla coil design program

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
