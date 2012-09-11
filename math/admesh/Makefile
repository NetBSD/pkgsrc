# $NetBSD: Makefile,v 1.12 2012/09/11 23:04:16 asau Exp $

DISTNAME=		admesh-0.95
CATEGORIES=		math
MASTER_SITES=		http://www.varlog.com/products/admesh/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.varlog.com/index.html
COMMENT=		Program for processing triangulated solid meshes

GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/admesh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/admesh
	cd ${WRKSRC} && ${INSTALL_DATA} README ADMESH.DOC \
		${DESTDIR}${PREFIX}/share/doc/admesh/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/admesh
	${INSTALL_DATA} ${WRKSRC}/block.stl \
		${DESTDIR}${PREFIX}/share/examples/admesh

.include "../../mk/bsd.pkg.mk"
