# $NetBSD: Makefile,v 1.26 2001/02/16 13:15:41 wiz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/06/19 05:30:04 ache Exp 
#

DISTNAME=	unzip542
PKGNAME=	unzip-5.42
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/zip/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://ftp.info-zip.org/pub/infozip/UnZip.html
COMMENT=	List, test and extract compressed files in a ZIP archive

MAKEFILE=	unix/Makefile
ALL_TARGET=	unzips
# we do not use USE_ZLIB because of unknown bugs in 5.40's use of libz
MAKE_FLAGS=	CF="${CFLAGS} -I. -DBSD -DUNIX -Dunix -DUSE_UNSHRINK"

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && ${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 \
		zipgrep.1 zipinfo.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS COPYING.OLD LICENSE README WHERE \
		${PREFIX}/share/doc/unzip

.include "../../mk/bsd.pkg.mk"
