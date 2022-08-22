# $NetBSD: Makefile,v 1.3 2022/08/22 10:44:16 wiz Exp $

DISTNAME=	libcyaml-1.3.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlsa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/tlsa/libcyaml
COMMENT=	Schema-based YAML parsing and serialization
LICENSE=	isc

USE_TOOLS+=	gmake pkg-config
NO_CONFIGURE=	yes

# The Makefile wants to add a bunch of options to install(1) specific to GNU
# install(1) -- disable those right here.
INSTALL_MAKE_FLAGS+=	INSTALL="install"

PKGCONFIG_OVERRIDE+=	libcyaml.pc.in

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
