# $NetBSD: Makefile,v 1.19 2020/04/29 19:57:51 maya Exp $

DISTNAME=	easydiskpasswd-1.0
PKGREVISION=	1
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool to unlock a password protected USB "EasyDisk"

WRKSRC=		${WRKDIR}
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}

INSTALLATION_DIRS=	bin

# we depend on SCIOCCOMMAND, a header defining sense codes
# and the "make" infrastructure
ONLY_FOR_PLATFORM=	NetBSD-*-*

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-traditional
.endif

do-extract:
	${CP} ${FILESDIR}/easydiskpasswd.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
