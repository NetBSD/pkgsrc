# $NetBSD: Makefile,v 1.1 2026/03/11 21:54:30 agc Exp $

DISTNAME=		depgraph-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Print dependency graph for packages
LICENSE=		modified-bsd

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKEFLAGS+=		SCRIPTSDIR=${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} -F= '/^DEPGRAPH_VERSION=/ {print $$2}' ${FILESDIR}/depgraph.sh

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
