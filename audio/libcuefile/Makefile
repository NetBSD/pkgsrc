# $NetBSD: Makefile,v 1.2 2020/01/26 17:30:42 rillig Exp $

DISTNAME=		libcuefile_r475
PKGNAME=		libcuefile-0rc475
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.musepack.net/
COMMENT=		CUE File library for the musepack decoder
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
INSTALLATION_DIRS=	include/cuetools

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/cuetools/* ${DESTDIR}${PREFIX}/include/cuetools

.include "../../mk/bsd.pkg.mk"
