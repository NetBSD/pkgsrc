# $NetBSD: Makefile,v 1.7 2018/01/28 16:25:36 wiz Exp $

DISTNAME=	onig-6.7.1
PKGNAME=	${DISTNAME:S/onig/oniguruma/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kkos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kkos/oniguruma
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	oniguruma
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	oniguruma.pc.in

.include "../../mk/bsd.pkg.mk"
