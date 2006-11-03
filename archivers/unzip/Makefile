# $NetBSD: Makefile,v 1.67 2006/11/03 19:14:25 joerg Exp $

DISTNAME=	unzip552
PKGNAME=	unzip-5.52
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/UnZip.html
COMMENT=	List, test and extract compressed files in a ZIP archive

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}	# Remove on next update.
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

MAKE_FILE=	unix/Makefile
BUILD_TARGET=	generic_zlib unzipsfx
.if ${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin"
CFLAGS+=	-DBSD
.endif
CFLAGS+=	-I. -DUNIX -Dunix -DUSE_UNSHRINK
MAKE_FLAGS+=	CF=${CPPFLAGS:Q}\ ${CFLAGS:Q}
MAKE_FLAGS+=	LF2=${_STRIPFLAG_CC:Q}\ ${LDFLAGS:Q}\ -lz

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc

TEST_TARGET=	check

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unzip funzip unzipsfx ${DESTDIR}${PREFIX}/bin
	${LN} -sf unzip ${DESTDIR}${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && ${INSTALL_SCRIPT} zipgrep ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 \
		zipgrep.1 zipinfo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS LICENSE README WHERE \
		${DESTDIR}${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING.OLD \
		${DESTDIR}${PREFIX}/share/doc/unzip/COPYING

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
