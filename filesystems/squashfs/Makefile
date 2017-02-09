# $NetBSD: Makefile,v 1.3 2017/02/09 18:16:07 scole Exp $

VERSION=        4.3
DISTNAME=       squashfs${VERSION}
PKGNAME=        squashfs-${VERSION}

PKGREVISION=	1
CATEGORIES=     filesystems
MASTER_SITES=   http://downloads.sourceforge.net/project/squashfs/squashfs/${DISTNAME}/

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://squashfs.sourceforge.net/
COMMENT=        Tools for squashfs archives
LICENSE=        gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_LANGUAGES=  c

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin \
			share/doc/squashfs \
			share/doc/squashfs/OLD-READMEs \
			share/examples/squashfs

SQUASH_DIR=	${WRKDIR}/${DISTNAME}
WRKSRC=		${SQUASH_DIR}/squashfs-tools
SQUASH_PKG_DOC=	${DESTDIR}${PREFIX}/share/doc/squashfs

do-build:
	cd ${WRKSRC} && env EXTRA_LDFLAGS="-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib" \
		${GMAKE} ${BUILD_MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksquashfs ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unsquashfs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA}	${SQUASH_DIR}/ACKNOWLEDGEMENTS   ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/CHANGES            ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/COPYING            ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/DONATIONS          ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/INSTALL            ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/PERFORMANCE.README ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/README             ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/README-4.3         ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/OLD-READMEs/*      ${SQUASH_PKG_DOC}/OLD-READMEs/
	${INSTALL_DATA}	${SQUASH_DIR}/pseudo-file.example ${DESTDIR}${PREFIX}/share/examples/squashfs/

.include "../../mk/bsd.pkg.mk"
