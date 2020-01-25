# $NetBSD: Makefile,v 1.3 2020/01/25 11:17:31 schmonz Exp $

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
INSTALL_TARGET=		install

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
