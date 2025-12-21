# $NetBSD: Makefile,v 1.28 2025/12/21 12:18:01 mef Exp $

DISTNAME=	pangox-compat-0.0.2
PKGREVISION=	18
CATEGORIES=	devel fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pangox-compat/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pango.org/
COMMENT=	Backwards compatibility library for pango X support
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

# work arround for older style programming (for gcc-14.3.0)
CFLAGS+=		-Wno-deprecated-declarations
CFLAGS+=		-Wno-implicit-function-declaration
CFLAGS+=		-Wno-int-conversion
CFLAGS+=		-Wno-incompatible-pointer-types

PKGCONFIG_OVERRIDE=	pangox.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
