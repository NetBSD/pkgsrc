# $NetBSD: Makefile,v 1.24 2019/04/25 07:32:58 maya Exp $

DISTNAME=	libepoxy-1.4.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=anholt/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anholt/libepoxy/
COMMENT=	Library for OpenGL function pointer management
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config autoconf autoreconf automake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	epoxy.pc.in
PYTHON_FOR_BUILD_ONLY=	yes

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
