# $NetBSD: Makefile,v 1.1 2014/04/18 12:38:22 wiz Exp $

DISTNAME=		libcuefile_r475
PKGNAME=		libcuefile-0rc475
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		CUE File library for the musepack decoder
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
INSTALLATION_DIRS=	include/cuetools

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/cuetools/* ${DESTDIR}${PREFIX}/include/cuetools

.include "../../mk/bsd.pkg.mk"
