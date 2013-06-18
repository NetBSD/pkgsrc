# $NetBSD: Makefile,v 1.17 2013/06/18 18:52:43 wiz Exp $
#

GIT_COMMIT=		89cccf
DISTNAME=		${GIT_COMMIT}
PKGNAME=		fs-utils-20130601

CATEGORIES=		filesystems
MASTER_SITES=		-http://nodeload.github.com/stacktic/fs-utils/tar.gz/${GIT_COMMIT}

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		https://github.com/stacktic/fs-utils
COMMENT=		Tools to access/modify a file system image through RUMP
LICENSE=		2-clause-bsd
DEPENDS+=		rump>=20130101:../../misc/rump

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-* NetBSD-*-* DragonFly-*-*

INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/fs-utils-${GIT_COMMIT}

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../misc/rump/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
