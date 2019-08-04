# $NetBSD: Makefile,v 1.25 2019/08/04 14:41:27 ryoon Exp $
#

VERSION=		20130705
PKGNAME=		rump-${VERSION}
DISTNAME=		buildrump-${VERSION}

CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		https://github.com/anttikantee/buildrump.sh
COMMENT=		Virtualized NetBSD kernel components in userspace
LICENSE=		2-clause-bsd
USE_TOOLS+=		pax

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-* NetBSD-*-* DragonFly-*-*

INSTALLATION_DIRS=	lib include/rump ${PKGMANDIR}/man3

WRKSRC=			${WRKDIR}/buildrump

CHECK_SHLIBS_SUPPORTED=	no

do-build:
	cd ${WRKSRC} && ./buildrump.sh -r tools build install

pre-install:
	rm -rf ${WRKSRC}/rump/share/man/cat*
	rmdir ${WRKSRC}/rump/share/man/man* || ${TRUE}

do-install:
	cd ${WRKSRC}/rump && ${PAX} -wr lib include share ${DESTDIR}${PREFIX}/

.include "../../mk/bsd.pkg.mk"
