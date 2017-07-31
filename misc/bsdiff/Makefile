# $NetBSD: Makefile,v 1.13 2017/07/31 07:09:54 nros Exp $
#

DISTNAME=		bsdiff-4.3
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.daemonology.net/bsdiff/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.daemonology.net/bsdiff/
COMMENT=		Size efficient binary diff and patch tools

USE_TOOLS+=		bzip2:run

MAKE_ENV+=		BZIP2=${BZIP2}
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
