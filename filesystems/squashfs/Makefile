# $NetBSD: Makefile,v 1.8 2020/06/19 21:17:46 scole Exp $

VERSION=	4.4
DISTNAME=	squashfs-tools-${VERSION}
PKGNAME=	squashfs-${VERSION}

CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=plougher/}
GITHUB_PROJECT=	squashfs-tools
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/plougher/squashfs-tools
COMMENT=	Tools for squashfs archives
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_LANGUAGES=	c

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin \
			share/doc/squashfs \
			share/doc/squashfs/RELEASE-READMEs

SQUASH_DIR=	${WRKDIR}/${DISTNAME}
WRKSRC=		${SQUASH_DIR}/squashfs-tools
SQUASH_PKG_DOC=	${DESTDIR}${PREFIX}/share/doc/squashfs

# xxx no sigtimedwait or sigwaitinfo on mac os?
BROKEN_ON_PLATFORM=	Darwin-*-*

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/mksquashfs ${DESTDIR}${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/unsquashfs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA}	${SQUASH_DIR}/ACKNOWLEDGEMENTS   ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/CHANGES            ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/COPYING            ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/INSTALL            ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/README             ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/README-4.4         ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/USAGE              ${SQUASH_PKG_DOC}
	${INSTALL_DATA}	${SQUASH_DIR}/RELEASE-READMEs/* \
		${SQUASH_PKG_DOC}/RELEASE-READMEs/

.include "../../mk/bsd.pkg.mk"
