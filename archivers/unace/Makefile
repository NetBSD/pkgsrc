# $NetBSD: Makefile,v 1.26 2019/11/02 22:54:28 rillig Exp $
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
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gmake

BUILD_TARGET=	clean unace

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/unace
	${INSTALL_MAN} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/unace

.include "../../mk/bsd.pkg.mk"
