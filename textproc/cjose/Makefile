# $NetBSD: Makefile,v 1.7 2026/06/13 10:02:33 markd Exp $

DISTNAME=	cjose-0.6.2.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenIDC/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cisco/cjose/
COMMENT=	C implementation of JOSE
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	cjose.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
