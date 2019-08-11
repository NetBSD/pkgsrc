# $NetBSD: Makefile,v 1.14 2019/08/11 13:21:16 wiz Exp $

DISTNAME=	ps2eps-1.68
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.tm.uka.de/~bless/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tm.uka.de/~bless/ps2eps
COMMENT=	Tool for generating EPS Format files from one-page PS documents
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}/ps2eps

REPLACE_PERL+=	bin/ps2eps

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}/src/C && ${CC} ${CFLAGS} ${LDFLAGS} -o bbox bbox.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/C/bbox ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ps2eps ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
