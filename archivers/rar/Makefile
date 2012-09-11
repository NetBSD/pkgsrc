# $NetBSD: Makefile,v 1.54 2012/09/11 19:47:00 asau Exp $
#

DISTNAME=	# overridden
PKGNAME=	rar-${RAR_VER}
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlabs.com/rar/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.rarlabs.com/rar/
COMMENT=	RAR file archiver (binary)
LICENSE=	rar-license

RAR_VER=	4.1.1

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-i386 linux-x86_64

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar
USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTFILES=	rarlinux-${RAR_VER}.tar.gz
.elif ${EMUL_PLATFORM} == "linux-x86_64"
DISTFILES=	rarlinux-x64-${RAR_VER}.tar.gz
.endif

DOCSDIR=		share/doc/rar

INSTALLATION_DIRS=	bin etc lib ${DOCSDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar_static ${DESTDIR}${PREFIX}/bin/rar

	${INSTALL_LIB} ${WRKSRC}/default.sfx ${DESTDIR}${PREFIX}/lib

	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${DESTDIR}${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/${DOCSDIR}
.include "../../mk/bsd.pkg.mk"
