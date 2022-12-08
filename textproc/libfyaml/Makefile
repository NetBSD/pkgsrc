# $NetBSD: Makefile,v 1.1 2022/12/08 19:16:20 khorben Exp $

DISTNAME=	libfyaml-0.7.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pantoniou/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pantoniou/libfyaml/
COMMENT=	Feature-complete YAML parser and emitter
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libfyaml.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/bsd.pkg.mk"
