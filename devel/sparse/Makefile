# $NetBSD: Makefile,v 1.13 2019/08/11 13:20:51 wiz Exp $

DISTNAME=	sparse-0.4.4
PKGREVISION=	6
CATEGORIES=	devel lang
MASTER_SITES=	https://kernel.org/pub/software/devel/sparse/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://kernel.org/pub/software/devel/sparse/
COMMENT=	Semantic parser for C
# The license in the tarball appears to be a different (older) version
# from the one in pkgsrc/licenses. I have no idea how significant this
# might be.
#LICENSE=	osl

INSTALLATION_DIRS+=	share/doc/sparse
PKGCONFIG_OVERRIDE+=	sparse.pc.in
REPLACE_PERL=		cgcc
USE_TOOLS+=		gmake perl:run

post-install:
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sparse/

.include "../../mk/bsd.pkg.mk"
