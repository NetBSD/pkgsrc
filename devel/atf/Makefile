# $NetBSD: Makefile,v 1.29 2026/09/02 15:35:03 adam Exp $

DISTNAME=	atf-0.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=freebsd/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freebsd/atf
COMMENT=	Automated testing framework
LICENSE=	2-clause-bsd

CONFLICTS+=		atf-libs<0.20

USE_CXX_FEATURES=	c++20
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	ATF_SHELL=${SH:Q}

PKGCONFIG_OVERRIDE=	atf-c/atf-c.pc.in
PKGCONFIG_OVERRIDE+=	atf-c++/atf-c++.pc.in
PKGCONFIG_OVERRIDE+=	atf-sh/atf-sh.pc.in

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
