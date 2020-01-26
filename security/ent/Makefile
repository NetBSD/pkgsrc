# $NetBSD: Makefile,v 1.2 2020/01/26 17:32:02 rillig Exp $
#

DISTNAME=		random
PKGNAME=		ent-19981020
CATEGORIES=		security
MASTER_SITES=		http://fourmilab.ch/random/
EXTRACT_SUFX=		.zip

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		https://fourmilab.ch/random/
COMMENT=		Entropy calculation and analysis of putative random sequences
LICENSE=		public-domain

DIST_SUBDIR=		${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}
BUILD_TARGET=		${EMPTY}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ent ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
