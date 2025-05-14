# $NetBSD: Makefile,v 1.18 2025/05/14 06:52:11 wiz Exp $

DISTNAME=	ps2eps-1.70
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=roland-bless/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/roland-bless/ps2eps
COMMENT=	Tool for generating EPS Format files from one-page PS documents
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run

REPLACE_PERL+=	src/perl/ps2eps

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}/src/C && ${CC} ${CFLAGS} ${LDFLAGS} -o bbox bbox.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/C/bbox ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/perl/ps2eps ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
