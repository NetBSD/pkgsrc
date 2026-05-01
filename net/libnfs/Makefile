# $NetBSD: Makefile,v 1.1 2026/05/01 19:43:30 vins Exp $

DISTNAME=	libnfs-6.0.2
CATEGORIES=	net filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=sahlberg/}
GITHUB_TAG=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sahlberg/libnfs
COMMENT=	NFS client library
# LGPL applies to the library itself, while GPL applies to the utilities.
# BSD applies to other misc files.
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3 AND 2-clause-bsd

PKGCONFIG_OVERRIDE=	cmake/libnfs.pc.cmake

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release \
			-DCMAKE_INSTALL_PREFIX='${PREFIX}' \
			-DINSTALL_MAN_DIR:PATH='${PREFIX}/${PKGMANDIR}' \
			-DENABLE_UTILS:BOOL=ON \
			-DENABLE_DOCUMENTATION:BOOL=ON

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
