# $NetBSD: Makefile,v 1.15 2012/10/23 19:51:00 asau Exp $

DISTNAME=	easydiskpasswd-1.0
PKGREVISION=	1
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	Tool to unlock a password protected USB "EasyDisk"

WRKSRC=		${WRKDIR}
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}

INSTALLATION_DIRS=	bin

# we depend on SCIOCCOMMAND, a header defining sense codes
# and the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-[3-9]*-*

do-extract:
	${CP} ${FILESDIR}/easydiskpasswd.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
