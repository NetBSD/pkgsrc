# $NetBSD: Makefile,v 1.1 2026/05/02 07:01:14 vins Exp $

DISTNAME=	libimobiledevice-1.4.0
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Libraries and tools to communicate with iOS devices
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake bash pkg-config

GNU_CONFIGURE=	yes
CONFIG_SHELL=	bash

PY_PATCHPLIST=	yes

post-extract:
# By default, configure script uses a git wrapper to hard-code the current version.
	@${STEP_MSG} "Setting package version to ${PKGVERSION_NOREV}"
	${RUN}${ECHO} ${PKGVERSION_NOREV} > ${WRKSRC}/.tarball-version

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/py-cython/tool.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../security/libtatsu/buildlink3.mk"
.include "../../comms/libusbmuxd/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
