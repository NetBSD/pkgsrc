# $NetBSD: Makefile,v 1.1.1.1 2002/01/04 21:02:30 fredb Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
CATEGORIES=	misc archivers
MASTER_SITES=	http://telia.dl.sourceforge.net/parchive/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://sourceforge.net/project/parchive/
COMMENT=	create or use "Parity Volume Set" (PAR and Pnn) files

WRKSRC=		${WRKDIR}/par-cmdline

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
