# $NetBSD: Makefile,v 1.10 2007/02/22 19:27:12 wiz Exp $
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

.include "../../mk/bsd.pkg.mk"
