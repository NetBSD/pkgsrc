# $NetBSD: Makefile,v 1.13 2020/03/20 11:58:02 nia Exp $
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
