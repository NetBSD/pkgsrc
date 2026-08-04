# $NetBSD: Makefile,v 1.28 2026/08/04 20:28:43 wiz Exp $
#

DISTNAME=	unace-1.2b
PKGNAME=	unace-1.2.2
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives
LICENSE=	unace-source-license

# clang: error: no such file or directory: 'uac_crc.o'
MAKE_JOBS_SAFE=	no

RESTRICTED=		Only original file distribution.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_TOOLS+=	gmake

BUILD_TARGET=	clean unace

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/unace
	${INSTALL_MAN} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/unace

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
