# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 22:57:42 cheusov Exp $

PKGNAME=	heirloom-doc-${HEIRLOOM_VER}
CATEGORIES=	sysutils

.include "../../sysutils/heirloom-doc/Makefile.common"

MAINTAINER=	cheusov@tut.by

DOC_FILES=	COPYING COPYING.LGPL \
		LICENSE LUCENT \
		OPENSOLARIS.LICENSE README

DOC_DIR=		${PREFIX}/share/doc/${PKGBASE}
MAN1_DIR=		${PREFIX}/${HLROOT}/man/man1

INSTALLATION_DIRS+=	${DOC_DIR} ${DOC_DIR}/LICENSE ${MAN1_DIR}

MAKE_FLAGS+=		SUBDIRS=build

do-build:
	cd ${WRKSRC}/build && ${MAKE} && cd .. && ${MAKE} -f Makefile intro.1

do-install:
	set -e; \
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOC_DIR}; \
	for i in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/LICENSE/"$${i}" \
		                ${DESTDIR}${DOC_DIR}/LICENSE; \
	done; \
	${INSTALL_MAN} ${WRKSRC}/intro.1 ${DESTDIR}${MAN1_DIR}

.include "../../mk/bsd.pkg.mk"
