# $NetBSD: Makefile,v 1.124 2025/09/21 15:11:37 wiz Exp $

DISTNAME=	autotrace-0.31.10
PKGREVISION=	7
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
