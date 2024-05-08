# $NetBSD: Makefile,v 1.7 2024/05/08 12:53:30 adam Exp $

DISTNAME=	erfa-2.0.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=liberfa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/liberfa/erfa
COMMENT=	Essential Routines for Fundamental Astronomy
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE+=	erfa.pc.in

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

AUTOCONF_REQD+=	2.50
AUTOMAKE_REQD+=	1.7.1

pre-configure:
	set -e; cd ${WRKSRC}; \
	./bootstrap.sh; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
