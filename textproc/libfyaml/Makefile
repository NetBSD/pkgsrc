# $NetBSD: Makefile,v 1.2 2022/12/14 15:38:59 wiz Exp $

DISTNAME=	libfyaml-0.7.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pantoniou/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
# remove on next update
DIST_SUBDIR=	libfyaml-0.7.12

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pantoniou/libfyaml/
COMMENT=	Feature-complete YAML parser and emitter
LICENSE=	mit

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libfyaml.pc.in

.include "../../mk/bsd.pkg.mk"
