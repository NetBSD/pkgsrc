# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:51 jmmv Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
WRKSRC=		${WRKDIR}/par-cmdline
CATEGORIES=	misc archivers
MASTER_SITES=	http://telia.dl.sourceforge.net/parchive/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://sourceforge.net/project/parchive/
COMMENT=	create or use "Parity Volume Set" (PAR and Pnn) files

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
