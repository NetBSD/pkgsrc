# $NetBSD: Makefile,v 1.4 2003/07/21 17:01:25 martti Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
WRKSRC=		${WRKDIR}/par-cmdline
CATEGORIES=	misc archivers
MASTER_SITES=	http://telia.dl.sourceforge.net/parchive/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/project/parchive/
COMMENT=	Create or use "Parity Volume Set" (PAR and Pnn) files

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
