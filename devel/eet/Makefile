# $NetBSD: Makefile,v 1.32 2020/05/01 00:03:10 joerg Exp $
#

DISTNAME=	eet-1.7.10
CATEGORIES=	devel archivers
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.enlightenment.org/
COMMENT=	Library for speedy storage, retrieval, and compression
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

INSTALLATION_DIRS=	share/doc/eet

CONFIGURE_ARGS+=	--enable-tests

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/AUTHORS \
	    ${DESTDIR}${PREFIX}/share/doc/eet

.include "../../devel/eina/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
