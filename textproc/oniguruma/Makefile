# $NetBSD: Makefile,v 1.26 2023/10/19 14:44:45 wiz Exp $

DISTNAME=	onig-6.9.9
PKGNAME=	${DISTNAME:S/onig/oniguruma/}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kkos/}
GITHUB_PROJECT=	oniguruma
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kkos/oniguruma
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

#WRKSRC=		${WRKDIR}/${DISTNAME:R}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-binary-compatible-posix-api=yes
PKGCONFIG_OVERRIDE=	oniguruma.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
