# $NetBSD: Makefile,v 1.11 2005/12/05 20:49:55 rillig Exp $
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
DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_ENV+=	BINDIR=${PREFIX}/bin BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}

INSTALLATION_DIRS=	bin

do-extract:
	# deal with the dos encoding of the file
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR}/chef.l.tmp
	cd ${WRKSRC} && ${TR} '\015' '\n' < chef.l.tmp > chef.l
	cd ${WRKSRC} && ${RM} chef.l.tmp

do-build:
	cd ${WRKSRC} && ${LEX} chef.l
	${LINK.c} -o ${WRKSRC}/chef ${WRKSRC}/lex.yy.c -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chef ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
