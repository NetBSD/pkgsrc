# $NetBSD: Makefile,v 1.14 2014/06/13 14:02:53 jperkin Exp $

DISTNAME=	pbulk-base-0.48
COMMENT=	Core components of the modular bulk build framework

.include "../../pkgtools/pbulk/Makefile.common"

USE_FEATURES=	nbcompat
USE_TOOLS+=	nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1
USE_BSD_MAKEFILE=	yes

MAKE_FLAGS+=		CWARNFLAGS.clang=-Wno-error=missing-noreturn

CONFLICTS=	pbulk<0.39

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDADD+=		-lsocket -lresolv
MAKE_ENV+=	LDADD=${LDADD:Q}
.endif

.if ${OPSYS} == "Linux"
CPPFLAGS+=	-D_GNU_SOURCE
.endif

BUILD_DIRS=	lib pbuild presolve pscan

do-extract:
	${CP} -r ${FILESDIR}/pbulk ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
