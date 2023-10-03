# $NetBSD: Makefile,v 1.9 2023/10/03 19:26:20 scole Exp $

VERSION=	4.6.1
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
			man \
			man/man1 \
			share/doc/squashfs \
			share/doc/squashfs/examples

SQUASH_DIR=	${WRKDIR}/${DISTNAME}
WRKSRC=		${SQUASH_DIR}/squashfs-tools
SQUASH_PKG_DOC=	${DESTDIR}${PREFIX}/share/doc/squashfs
SQUASH_DOCS=	ACKNOWLEDGEMENTS ACTIONS-README CHANGES COPYING INSTALL \
		README-4.6.1 TECHNICAL-INFO USAGE-4.6 USAGE-MKSQUASHFS-4.6 \
		USAGE-SQFSCAT-4.6 USAGE-SQFSTAR-4.6 USAGE-UNSQUASHFS-4.6
SQUASH_MAN=	mksquashfs.1 sqfscat.1 sqfstar.1 unsquashfs.1

# xxx no sigtimedwait or sigwaitinfo on mac os?
BROKEN_ON_PLATFORM=	Darwin-*-*

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/mksquashfs ${DESTDIR}${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/unsquashfs ${DESTDIR}${PREFIX}/bin
	${LN} -f ${DESTDIR}${PREFIX}/bin/mksquashfs ${DESTDIR}${PREFIX}/bin/sqfstar
	${LN} -f ${DESTDIR}${PREFIX}/bin/unsquashfs ${DESTDIR}${PREFIX}/bin/sqfscat
	for f in ${SQUASH_DOCS}; do					\
		${INSTALL_DATA}	${SQUASH_DIR}/$$f ${SQUASH_PKG_DOC};	\
	done
	for f in ${SQUASH_MAN}; do					\
		${INSTALL_MAN} ${SQUASH_DIR}/manpages/$$f		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;			\
	done
	${INSTALL_DATA}	${SQUASH_DIR}/examples/pseudo-file.example \
		${SQUASH_PKG_DOC}/examples

.include "../../mk/bsd.pkg.mk"
