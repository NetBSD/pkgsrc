# $NetBSD: Makefile,v 1.2 2003/06/02 01:18:29 jschauma Exp $

DISTNAME=		mtl-2.1.2-21
CATEGORIES=		math devel
MASTER_SITES=		http://www.osl.iu.edu/download/research/mtl/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.osl.iu.edu/research/mtl/
COMMENT=		Matrix Template Library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
NO_BUILD=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mtl
	${INSTALL_DATA} ${WRKSRC}/contrib/examples/*.cc	\
		${PREFIX}/share/examples/mtl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtl
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL LICENSE README	\
		${PREFIX}/share/doc/mtl

.include "../../mk/bsd.pkg.mk"
