# $NetBSD: Makefile,v 1.3 2002/01/04 20:05:53 fredb Exp $
#

DISTNAME=	par-v1.1
CATEGORIES=	misc archivers
MASTER_SITES=	http://telia.dl.sourceforge.net/parchive/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://sourceforge.net/project/parchive/
COMMENT=	create or use "Parity Volume Set" (PAR and Pnn) files

WRKSRC=		${WRKDIR}/par-cmdline

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
