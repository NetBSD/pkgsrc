# $NetBSD: Makefile,v 1.4 2025/08/12 09:15:14 adam Exp $

DISTNAME=	libcuefile_r475
PKGNAME=	libcuefile-0rc475
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musepack.net/
COMMENT=	CUE File library for the musepack decoder
LICENSE=	gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

INSTALLATION_DIRS=	include/cuetools

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/cuetools/* ${DESTDIR}${PREFIX}/include/cuetools

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
