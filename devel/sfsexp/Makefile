# $NetBSD: Makefile,v 1.2 2023/04/26 19:36:49 wiz Exp $

DISTNAME=	sfsexp-1.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjsottile/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mjsottile/sfsexp/
COMMENT=	Small Fast S-Expression Library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	sfsexp.pc.in

.include "../../mk/bsd.pkg.mk"
