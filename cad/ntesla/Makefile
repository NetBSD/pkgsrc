# $NetBSD: Makefile,v 1.3 2000/05/12 16:07:35 dmcmahill Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
