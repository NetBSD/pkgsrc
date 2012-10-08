# $NetBSD: Makefile,v 1.11 2012/10/08 09:57:34 asau Exp $
#

DISTNAME=	par-v1.1
PKGNAME=	parchive-1.1
PKGREVISION=	1
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parchive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://parchive.sourceforge.net/
COMMENT=	Create or use "Parity Volume Set" (PAR and Pnn) files

WRKSRC=		${WRKDIR}/par-cmdline

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${DESTDIR}${PREFIX}/bin/parchive

.include "../../mk/bsd.pkg.mk"
