# $NetBSD: Makefile,v 1.4 2023/08/02 19:21:51 nia Exp $
#

DISTNAME=	fuse-sparsebundlefs-20160928
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=torarnv/}
GITHUB_PROJECT=	sparsebundlefs
GITHUB_TAG=	f3ccd20bd6393b05c9949810feb0e0b366b86348

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/torarnv/sparsebundlefs
COMMENT=	FUSE filesystem for reading Mac OS sparse-bundle disk images
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sparsebundlefs ${DESTDIR}/${PREFIX}/bin/

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
