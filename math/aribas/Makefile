# $NetBSD: Makefile,v 1.22 2021/04/24 19:36:25 wiz Exp $

DISTNAME=	aribas-1.63
CATEGORIES=	math
MASTER_SITES=	https://www.mathematik.uni-muenchen.de/~forster/sw/UNIX_LINUX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html
COMMENT=	Multi-precision floating point and big integer arithmetic calculator

CPPFLAGS+=	-DUNiX -DPROTO

BUILD_DIRS=	src

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aribas ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/aribas.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/aribas
	${INSTALL_DATA} ${WRKSRC}/doc/aribas.[dmt]* \
		${DESTDIR}${PREFIX}/share/doc/aribas/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/aribas
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/aribas/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/src/EL/aribas.el \
		${DESTDIR}${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
