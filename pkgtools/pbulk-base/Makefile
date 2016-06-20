# $NetBSD: Makefile,v 1.23 2016/06/20 17:54:43 joerg Exp $

DISTNAME=	pbulk-base-0.52
COMMENT=	Core components of the modular bulk build framework

.include "../../pkgtools/pbulk/Makefile.common"

USE_FEATURES=	nbcompat
USE_TOOLS+=	nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1
USE_BSD_MAKEFILE=	yes

MAKE_FLAGS+=		CWARNFLAGS.clang=-Wno-error=missing-noreturn

CONFLICTS=	pbulk<0.39

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.8*)
CPPFLAGS+=	-Wno-clobbered
.endif

CPPFLAGS.Linux+=	-D_GNU_SOURCE
LDFLAGS.SunOS+=		-lsocket -lresolv

BUILD_DIRS=	lib pbuild presolve pscan

do-extract:
	${CP} -r ${FILESDIR}/pbulk ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
