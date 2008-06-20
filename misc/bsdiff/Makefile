# $NetBSD: Makefile,v 1.9 2008/06/20 01:09:25 joerg Exp $
#

DISTNAME=		bsdiff-4.3
CATEGORIES=		misc
MASTER_SITES=		http://www.daemonology.net/bsdiff/

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.daemonology.net/bsdiff/
COMMENT=		Size efficient binary diff and patch tools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		bzip2:run

MAKE_ENV+=		BZIP2=${BZIP2}

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
