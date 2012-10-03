# $NetBSD: Makefile,v 1.3 2012/10/03 21:55:55 wiz Exp $
#

DISTNAME=	sparse-0.3
PKGREVISION=	1
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
