# $NetBSD: Makefile,v 1.15 2013/05/26 17:25:30 stacktic Exp $
#

GIT_COMMIT=		07383d
DISTNAME=		${GIT_COMMIT}
PKGNAME=		fs-utils-20130519

CATEGORIES=		filesystems
MASTER_SITES=		-http://nodeload.github.com/stacktic/fs-utils/tar.gz/${GIT_COMMIT}

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		https://github.com/stacktic/fs-utils
COMMENT=		Tools to access/modify a file system image through RUMP
LICENSE=		2-clause-bsd
DEPENDS+=		rump-2013[0-9]*:../../misc/rump

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-* NetBSD-*-* DragonFly-*-*

INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/fs-utils-${GIT_COMMIT}

GNU_CONFIGURE=

.include "../../misc/rump/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
