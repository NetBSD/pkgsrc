# $NetBSD: Makefile,v 1.5 2003/08/25 20:23:06 fredb Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/par-cmdline
CATEGORIES=	misc archivers
MASTER_SITES=	http://telia.dl.sourceforge.net/parchive/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/project/parchive/
COMMENT=	Create or use "Parity Volume Set" (PAR and Pnn) files

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
