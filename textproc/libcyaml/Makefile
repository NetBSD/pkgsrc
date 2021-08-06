# $NetBSD: Makefile,v 1.1 2021/08/06 12:29:23 nia Exp $

DISTNAME=	libcyaml-1.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlsa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dressupgeekout@gmail.com
HOMEPAGE=	https://github.com/tlsa/libcyaml
COMMENT=	Schema-based YAML parsing and serialization
LICENSE=	isc

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

# The Makefile wants to add a bunch of options to install(1) specific to GNU
# install(1) -- disable those right here.
INSTALL_MAKE_FLAGS+=	INSTALL="install"

PKGCONFIG_OVERRIDE+=	libcyaml.pc.in

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
