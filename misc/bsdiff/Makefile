# $NetBSD: Makefile,v 1.15 2020/01/26 17:31:42 rillig Exp $
#

DISTNAME=		bsdiff-4.3
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.daemonology.net/bsdiff/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.daemonology.net/bsdiff/
COMMENT=		Size efficient binary diff and patch tools
LICENSE=		2-clause-bsd

USE_TOOLS+=		bzip2:run

MAKE_ENV+=		BZIP2=${BZIP2}
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
