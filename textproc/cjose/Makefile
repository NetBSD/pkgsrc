# $NetBSD: Makefile,v 1.5 2023/08/22 11:50:02 wiz Exp $

DISTNAME=	cjose-0.6.2.2
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
