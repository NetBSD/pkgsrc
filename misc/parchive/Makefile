# $NetBSD: Makefile,v 1.3 2003/07/17 21:49:45 grant Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
WRKSRC=		${WRKDIR}/par-cmdline
CATEGORIES=	misc archivers
MASTER_SITES=	http://telia.dl.sourceforge.net/parchive/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/project/parchive/
COMMENT=	create or use "Parity Volume Set" (PAR and Pnn) files

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
