# $NetBSD: Makefile,v 1.6 2003/09/19 23:08:25 dent Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/par-cmdline
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parchive/}

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://parchive.sourceforge.net/
COMMENT=	Create or use "Parity Volume Set" (PAR and Pnn) files

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
