# $NetBSD: Makefile,v 1.1 2015/12/11 14:10:42 wiz Exp $

DISTNAME=	highway-1.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tkengo/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://github.com/tkengo/highway
COMMENT=	High performance source code search tool
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake autoreconf gmake

pre-configure:
	cd ${WRKSRC} && ${MKDIR} config && autoreconf -fiv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
