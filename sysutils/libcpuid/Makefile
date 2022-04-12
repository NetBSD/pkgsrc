# $NetBSD: Makefile,v 1.1 2022/04/12 22:22:26 nikita Exp $

DISTNAME=		v${VERSION}
PKGNAME=		${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
VERSION=		0.5.1
GITHUB_PROJECT=		libcpuid
GITHUB_TAG=		${DISTNAME}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=anrieff/}
DIST_SUBDIR=		${GITHUB_PROJECT}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/anrieff/libcpuid/
COMMENT=		Small x86 CPU identification library
LICENSE=		2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c
USE_TOOLS=		autoconf automake

pre-configure:
	cd ${WRKSRC} && autoreconf --install

# only for a couple of archs, specify here.

.include "../../mk/bsd.pkg.mk"
