# $NetBSD: Makefile,v 1.1.1.1 2013/04/25 16:24:54 agc Exp $
#

DISTNAME=		random
PKGNAME=		ent-19981020
CATEGORIES=		security
MASTER_SITES=		http://fourmilab.ch/random/
EXTRACT_SUFX=		.zip

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://fourmilab.ch/random/
COMMENT=		Entropy calculation and analysis of putative random sequences
LICENSE=		public-domain

DIST_SUBDIR=		${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}
BUILD_TARGET=		${EMPTY}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ent ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
