# $NetBSD: Makefile,v 1.22 2000/04/20 03:13:55 wiz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/06/19 05:30:04 ache Exp 
#

DISTNAME=	unzip541
PKGNAME=	unzip-5.41
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://ftp.info-zip.org/pub/infozip/UnZip.html

MAKEFILE=	unix/Makefile
ALL_TARGET=	unzips
# we do not use USE_ZLIB because of unknown bugs in 5.40's use of libz
MAKE_FLAGS=	CF="${CFLAGS} -I. -DBSD -DUNIX -Dunix -DUSE_UNSHRINK"

BUILD_DEFS+=	ZIP_ENCRYPTION

.include "../../mk/bsd.prefs.mk"

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && ${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 \
		zipgrep.1 zipinfo.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING LICENSE README WHERE \
		${PREFIX}/share/doc/unzip

.include "../../mk/bsd.pkg.mk"
