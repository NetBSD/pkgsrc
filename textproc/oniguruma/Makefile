# $NetBSD: Makefile,v 1.12 2018/12/12 12:46:58 adam Exp $

DISTNAME=	onig-6.9.1
PKGNAME=	${DISTNAME:S/onig/oniguruma/}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kkos/}
GITHUB_PROJECT=	oniguruma
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kkos/oniguruma
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	oniguruma.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
