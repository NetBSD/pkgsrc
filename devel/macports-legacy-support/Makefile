# $NetBSD: Makefile,v 1.1 2023/11/15 15:23:13 nia Exp $

DISTNAME=	macports-legacy-support-1.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=macports/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/macports/macports-legacy-support
COMMENT=	Support for missing functions in legacy Mac OS X
LICENSE=	apple-public-source-license AND mit

USE_TOOLS+=	gmake

MAKE_JOBS_SAFE=	no

# Disable building the wrapped libSystem, through pkgsrc we can link with
# legacy support explicitly.
BUILD_TARGET=	dlib slib
INSTALL_TARGET=	install-dlib install-slib install-headers

ONLY_FOR_PLATFORM+=	Darwin-*-*

# PLIST depends on OS version.
GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} lib include \( -type f -o -type l \) -print | ${SORT};

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS_VERSION} < 100500
CWRAPPERS_APPEND.cc+=	-isystem ${WRKSRC}/tiger_only/include
.endif

pre-configure:
	${RM} ${WRKSRC}/src/macports_legacy_atexit.c

post-install:
.if ${OPSYS_VERSION} < 100500
	${CP} -Rp ${WRKSRC}/tiger_only/include/* ${DESTDIR}${PREFIX}/include/LegacySupport
.endif

.include "../../mk/bsd.pkg.mk"
