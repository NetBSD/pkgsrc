# $NetBSD: Makefile,v 1.121 2025/04/24 14:14:12 wiz Exp $

DISTNAME=	autotrace-0.31.10
PKGREVISION=	4
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=autotrace/}
GITHUB_PROJECT=	autotrace
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/autotrace/autotrace
COMMENT=	Convert bitmap to vector graphics
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_TOOLS+=		autoconf automake autopoint autoreconf intltool pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	autotrace.pc.in

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/pstoedit/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
