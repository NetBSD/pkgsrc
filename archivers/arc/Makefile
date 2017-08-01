# $NetBSD: Makefile,v 1.36 2017/08/01 14:58:51 wiz Exp $

DISTNAME=	arc-5.21p
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/arc/
COMMENT=	Create & extract files from DOS .ARC files

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/marc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
