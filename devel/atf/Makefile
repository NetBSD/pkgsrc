# $NetBSD: Makefile,v 1.28 2025/03/30 07:51:54 wiz Exp $

DISTNAME=	atf-0.23
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=freebsd/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freebsd/atf/
COMMENT=	Automated testing framework
LICENSE=	2-clause-bsd

CONFLICTS+=		atf-libs<0.20

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++14
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	ATF_SHELL=${SH:Q}

PKGCONFIG_OVERRIDE=	atf-c/atf-c.pc.in
PKGCONFIG_OVERRIDE+=	atf-c++/atf-c++.pc.in
PKGCONFIG_OVERRIDE+=	atf-sh/atf-sh.pc.in

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
