# $NetBSD: Makefile,v 1.7 2004/01/20 12:21:02 agc Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
PKGREVISION=	1
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parchive/}

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://parchive.sourceforge.net/
COMMENT=	Create or use "Parity Volume Set" (PAR and Pnn) files

WRKSRC=		${WRKDIR}/par-cmdline

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
