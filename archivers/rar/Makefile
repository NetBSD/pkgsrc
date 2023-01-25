# $NetBSD: Makefile,v 1.57 2023/01/25 21:35:21 wiz Exp $

DISTNAME=	rarlinux${EMUL_PLATFORM:S|linux-x86_64|-x64|:S|linux-i386|-x32|}-${PKGVER:S/.//}
PKGNAME=	rar-${PKGVER}
PKGVER=		6.20
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlabs.com/rar/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.rarlabs.com/
COMMENT=	RAR file archiver (binary)
LICENSE=	rar-license

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	base

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar
USE_LANGUAGES=	# none

DOCSDIR=		share/doc/rar

INSTALLATION_DIRS=	bin etc lib ${DOCSDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${DESTDIR}${PREFIX}/bin/rar

	${INSTALL_LIB} ${WRKSRC}/default.sfx ${DESTDIR}${PREFIX}/lib

	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${DESTDIR}${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/${DOCSDIR}
.include "../../mk/bsd.pkg.mk"
