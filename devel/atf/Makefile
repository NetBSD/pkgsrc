# $NetBSD: Makefile,v 1.26 2017/02/22 11:46:58 wiz Exp $

DISTNAME=	atf-0.21
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmmv/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://github.com/jmmv/atf/
COMMENT=	Automated testing framework
LICENSE=	2-clause-bsd

CONFLICTS+=		atf-libs<0.20

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	ATF_SHELL=${SH:Q}

PKGCONFIG_OVERRIDE=	atf-c/atf-c.pc.in
PKGCONFIG_OVERRIDE+=	atf-c++/atf-c++.pc.in
PKGCONFIG_OVERRIDE+=	atf-sh/atf-sh.pc.in

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
