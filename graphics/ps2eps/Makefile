# $NetBSD: Makefile,v 1.10 2016/07/09 06:38:22 wiz Exp $

DISTNAME=	ps2eps-1.68
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.tm.uka.de/~bless/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tm.uka.de/~bless/ps2eps
COMMENT=	Tool for generating EPS Format files from one-page PS documents

USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}/ps2eps

REPLACE_PERL+=	bin/ps2eps

INSTALLATION_DIRS+=	bin man/man1

do-build:
	cd ${WRKSRC:Q}/src/C && ${CC} ${CFLAGS} -o bbox bbox.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/src/C/bbox ${DESTDIR:Q}${PREFIX:Q}/bin
	${INSTALL_SCRIPT} ${WRKSRC:Q}/bin/ps2eps ${DESTDIR:Q}${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/doc/man/man1/*.1 \
		${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man1

.include "../../mk/bsd.pkg.mk"
