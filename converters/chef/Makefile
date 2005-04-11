# $NetBSD: Makefile,v 1.7 2005/04/11 21:45:08 tv Exp $
#

DISTNAME=	chef.l
PKGNAME=	chef-19920415
CATEGORIES=	converters
MASTER_SITES=	http://www.evolutionzone.com/kulturezone/c-g.writing/
EXTRACT_SUFX=	.txt

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Convert from English to (mock) Swedish - Bork Bork Bork!

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

MAKE_ENV+=	BINDIR=${PREFIX}/bin BINOWN=${BINOWN} BINGRP=${BINGRP}

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR}/chef.l

do-build:
	cd ${WRKSRC} && ${LEX} chef.l
	${LINK.c} -o ${WRKSRC}/chef ${WRKSRC}/lex.yy.c -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chef ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
