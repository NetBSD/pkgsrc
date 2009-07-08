# $NetBSD: Makefile,v 1.2 2009/07/08 16:13:51 joerg Exp $
#

DISTNAME=	sparse-0.3
CATEGORIES=	devel lang
MASTER_SITES=	http://kernel.org/pub/software/devel/sparse/dist/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://kernel.org/pub/software/devel/sparse/
COMMENT=	Semantic parser for C

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	share/doc/sparse
PKGCONFIG_OVERRIDE+=	sparse.pc.in
REPLACE_PERL=		cgcc
USE_TOOLS+=		gmake perl:run

post-install:
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sparse/

.include "../../mk/bsd.pkg.mk"
