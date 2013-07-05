# $NetBSD: Makefile,v 1.18 2013/07/05 17:25:23 stacktic Exp $
#

GIT_COMMIT=		v1.00
DISTNAME=		${GIT_COMMIT}
PKGNAME=		fs-utils-20130701

CATEGORIES=		filesystems
MASTER_SITES=		https://github.com/stacktic/fs-utils/archive/
FETCH_USING=		curl

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		https://github.com/stacktic/fs-utils
COMMENT=		Tools to access/modify a file system image through RUMP
LICENSE=		2-clause-bsd
DEPENDS+=		rump>=20130101:../../misc/rump

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-* NetBSD-*-*

INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/fs-utils-1.00

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../misc/rump/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
