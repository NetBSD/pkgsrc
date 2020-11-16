# $NetBSD: Makefile,v 1.6 2020/11/16 10:51:43 schmonz Exp $

DISTNAME=		daemontools-encore-1.11
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/daemontools-encore/
COMMENT=		Collection of tools for managing UNIX services
LICENSE=		mit

CONFLICTS+=		daemontools-[0-9]*

DJB_RESTRICTED=		no

MAKE_ENV+=		PKGSRC_SHELL=${TOOLS_PLATFORM.sh}
TEST_TARGET=		rts
INSTALL_TARGET=		install

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
