# $NetBSD: Makefile,v 1.65 2006/09/09 02:41:54 obache Exp $

DISTNAME=	unzip552
PKGNAME=	unzip-5.52
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/UnZip.html
COMMENT=	List, test and extract compressed files in a ZIP archive

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
MAKE_FLAGS+=	CF=${CPPFLAGS:M*:Q}\ ${CFLAGS:M*:Q}
MAKE_FLAGS+=	LF2=${_STRIPFLAG_CC:Q}\ ${LDFLAGS:M*:Q}\ -lz

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc

TEST_TARGET=	check

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && ${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 \
		zipgrep.1 zipinfo.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS LICENSE README WHERE \
		${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING.OLD \
		${PREFIX}/share/doc/unzip/COPYING

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
