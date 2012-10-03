# $NetBSD: Makefile,v 1.22 2012/10/03 11:24:42 asau Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replacement getty for dialup ttys and a modem server

USE_TOOLS+=	nroff

MAKE_JOBS_SAFE=		no

MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=	LIBS=${LIBS:Q}
USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/cat5 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 \
			sbin share/examples/modemd

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
LIBS+=		-lutil
.endif

LIBS.SunOS+=	-lsocket -lnsl
CFLAGS.SunOS+=	-DFILIO_H -DNO_STRING_H -DNTELOPTS=40

.include "../../mk/bsd.pkg.mk"
