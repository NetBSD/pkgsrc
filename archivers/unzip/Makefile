# $NetBSD: Makefile,v 1.48 2004/04/22 04:02:24 tv Exp $

DISTNAME=	unzip550
PKGNAME=	unzip-5.50
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/zip/src/ \
		ftp://ftp.fu-berlin.de/unix/tools/archivers/unzip/

PATCH_SITES=		http://security.debian.org/pool/updates/main/u/unzip/
PATCHFILES=		unzip_5.50-1woody2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/UnZip.html
COMMENT=	List, test and extract compressed files in a ZIP archive

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

.include "../../mk/bsd.prefs.mk"

MAKEFILE=	unix/Makefile
ALL_TARGET=	generic_zlib unzipsfx
.if ${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin"
MAKE_FLAGS=	CF="${CPPFLAGS} ${CFLAGS} -I. -DBSD -DUNIX -Dunix -DUSE_UNSHRINK" LF2="${_STRIPFLAG_CC} ${LDFLAGS} -lz"
.else
MAKE_FLAGS=	CF="${CPPFLAGS} ${CFLAGS} -I. -DUNIX -Dunix -DUSE_UNSHRINK" LF2="${_STRIPFLAG_CC} ${LDFLAGS} -lz"
.endif

INSTALLATION_DIRS=	bin man/man1 share/doc

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && ${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 \
		zipgrep.1 zipinfo.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS LICENSE README WHERE \
		${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING.OLD \
		${PREFIX}/share/doc/unzip/COPYING

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
