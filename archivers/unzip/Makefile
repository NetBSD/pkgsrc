# $NetBSD: Makefile,v 1.41 2003/08/20 12:23:49 tron Exp $

DISTNAME=	unzip550
PKGNAME=	unzip-5.50
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/zip/src/ \
		ftp://ftp.fu-berlin.de/pub/unix/tools/archivers/unzip/

PATCH_SITES=		http://security.debian.org/pool/updates/main/u/unzip/
PATCHFILES=		unzip_5.50-1woody1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/UnZip.html
COMMENT=	List, test and extract compressed files in a ZIP archive

USE_BUILDLINK2=	yes

.include "../../mk/bsd.prefs.mk"

MAKEFILE=	unix/Makefile
ALL_TARGET=	generic_zlib unzipsfx
.if ${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin"
MAKE_FLAGS=	CF="${CFLAGS} -I. -DBSD -DUNIX -Dunix -DUSE_UNSHRINK" LF2="-lz ${_STRIPFLAG_CC} ${LDFLAGS}"
.else
MAKE_FLAGS=	CF="${CFLAGS} -I. -DUNIX -Dunix -DUSE_UNSHRINK" LF2="-lz ${_STRIPFLAG_CC} ${LDFLAGS}"
.endif

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && ${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 \
		zipgrep.1 zipinfo.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS COPYING.OLD LICENSE README WHERE \
		${PREFIX}/share/doc/unzip

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
