# $NetBSD: Makefile,v 1.3 2023/01/24 18:36:19 wiz Exp $

DISTNAME=		libcuefile_r475
PKGNAME=		libcuefile-0rc475
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.musepack.net/
COMMENT=		CUE File library for the musepack decoder
LICENSE=		gnu-gpl-v2

INSTALLATION_DIRS=	include/cuetools

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/cuetools/* ${DESTDIR}${PREFIX}/include/cuetools

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
