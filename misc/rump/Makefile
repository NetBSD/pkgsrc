# $NetBSD: Makefile,v 1.19 2013/05/26 17:23:44 stacktic Exp $
#

VERSION_TIMESTAMP=	1369495826
PKGNAME=		rump-20130525
DISTNAME=		buildrump-${VERSION_TIMESTAMP}
EXTRACT_SUFX=		.tar.bz2

CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		http://github.com/anttikantee/buildrump.sh
COMMENT=		Virtualized NetBSD kernel components in userspace
LICENSE=		2-clause-bsd
USE_TOOLS+=		pax

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-* NetBSD-*-* DragonFly-*-*

INSTALLATION_DIRS=	lib include/rump ${PKGMANDIR}/man3

WRKSRC=			${WRKDIR}/buildrump

do-build:
	cd ${WRKSRC} && ./buildrump.sh -r tools build install

do-install:
	cd ${WRKSRC}/rump && ${PAX} -wr lib include share ${DESTDIR}${PREFIX}/

.include "../../mk/bsd.pkg.mk"
