# $NetBSD: Makefile,v 1.1.1.1 2006/04/08 22:55:40 minskim Exp $

DISTNAME=	ps2eps-1.58
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
	${INSTALL_PROGRAM} ${WRKSRC:Q}/src/C/bbox ${PREFIX:Q}/bin
	${INSTALL_SCRIPT} ${WRKSRC:Q}/bin/ps2eps ${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/doc/man/man1/*.1 \
		${PREFIX:Q}/${PKGMANDIR:Q}/man1

.include "../../mk/bsd.pkg.mk"
