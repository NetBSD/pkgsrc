# $NetBSD: Makefile,v 1.2 2025/08/10 13:35:20 ryoon Exp $

DISTNAME=		libcpuid-0.8.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=anrieff/}
GITHUB_PROJECT=		libcpuid
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/anrieff/libcpuid/
COMMENT=		Small x86 CPU identification library
LICENSE=		2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c
USE_TOOLS=		autoconf automake

# Disable docs
CONFIGURE_ENV+=		ac_cv_prog_DOXYGEN= #empty

# only for a couple of archs, specify here.

.include "../../mk/bsd.pkg.mk"
