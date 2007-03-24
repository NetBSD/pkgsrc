# $NetBSD: Makefile,v 1.11 2007/03/24 19:21:32 joerg Exp $
#

DISTNAME=	setquota-0.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jurai.net/users/winter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# unknown
COMMENT=	Command line quota tools

# BSD oriented, haven't checked on other environment now
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-*

WRKSRC=		${WRKDIR}/setquota/
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP}

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.pkg.mk"
