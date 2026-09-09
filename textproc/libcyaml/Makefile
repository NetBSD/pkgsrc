# $NetBSD: Makefile,v 1.3.32.1 2026/09/09 03:18:57 charlotte Exp $

DISTNAME=	libcyaml-1.4.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlsa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/tlsa/libcyaml
COMMENT=	Schema-based YAML parsing and serialization
LICENSE=	isc

USE_TOOLS+=	gmake pkg-config
NO_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libcyaml.pc.in

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
