# $NetBSD: Makefile,v 1.4 2012/10/31 11:19:46 asau Exp $
#

DISTNAME=	sparse-0.3
PKGREVISION=	1
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
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sparse/

.include "../../mk/bsd.pkg.mk"
