# $NetBSD: Makefile,v 1.20 2012/09/11 23:04:16 asau Exp $

DISTNAME=	aribas-1.63
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.mathematik.uni-muenchen.de/pub/forster/aribas/UNIX_LINUX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html
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
