# $NetBSD: Makefile,v 1.1.1.1 2007/05/21 20:46:43 reed Exp $
#

DISTNAME=	sparse-0.3
CATEGORIES=	devel lang
MASTER_SITES=	http://kernel.org/pub/software/devel/sparse/dist/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://kernel.org/pub/software/devel/sparse/
COMMENT=	Semantic parser for C

INSTALLATION_DIRS+=	share/doc/sparse
PKGCONFIG_OVERRIDE+=	sparse.pc.in
REPLACE_PERL=		cgcc
USE_TOOLS+=		gmake perl:run

post-install:
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sparse/

.include "../../mk/bsd.pkg.mk"
