# $NetBSD: Makefile,v 1.1 2019/03/16 08:03:56 bsiegert Exp $

DISTNAME=       cjose-0.6.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}

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
