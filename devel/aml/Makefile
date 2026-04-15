# $NetBSD: Makefile,v 1.1 2026/04/15 08:01:12 kikadf Exp $

DISTNAME=	aml-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=any1/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/any1/aml/
COMMENT=	Another main loop library
LICENSE=	isc

# -D_POSIX_C_SOURCE=200809L
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE=1

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/aml1.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

SUBST_CLASSES+=		nogit
SUBST_STAGE.nogit=	pre-configure
SUBST_MESSAGE.nogit=	Set version
SUBST_FILES.nogit+=	meson.build
SUBST_SED.nogit+=	-e 's/git =/\#git =/g'
SUBST_SED.nogit+=	-e 's/git.found()/false/g'

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
