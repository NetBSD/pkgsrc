# $NetBSD: Makefile,v 1.17 2013/05/01 17:16:06 stacktic Exp $
#

GIT_COMMIT=		067df5
DISTNAME=		${GIT_COMMIT}
PKGNAME=		rump-20130430

CATEGORIES=		misc
MASTER_SITES=		-http://nodeload.github.com/anttikantee/buildrump.sh/tar.gz/${GIT_COMMIT}

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		http://github.com/anttikantee/buildrump.sh
COMMENT=		Virtualized NetBSD kernel components in userspace
LICENSE=		2-clause-bsd
USE_TOOLS+=		pax

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-* NetBSD-*-*

INSTALLATION_DIRS=	lib include/rump ${PKGMANDIR}/man3

WRKSRC=			${WRKDIR}/buildrump.sh-${GIT_COMMIT}

do-build:
	cd ${WRKSRC} && ./buildrump.sh -r checkout tools build install

do-install:
	cd ${WRKSRC}/rump && ${PAX} -wr lib include share ${DESTDIR}${PREFIX}/

.include "../../mk/bsd.pkg.mk"
