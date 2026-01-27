# $NetBSD: Makefile,v 1.30 2026/01/27 08:39:16 wiz Exp $

DISTNAME=	pangox-compat-0.0.2
PKGREVISION=	19
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

.include "../../mk/compiler.mk"

# workaround for older-style programming (GCC >= 14)
.if ${PKGSRC_COMPILER:Mgcc}
CFLAGS+=	-Wno-error=deprecated-declarations
CFLAGS+=	-Wno-error=implicit-function-declaration
CFLAGS+=	-Wno-error=int-conversion
CFLAGS+=	-Wno-error=incompatible-pointer-types
.endif

PKGCONFIG_OVERRIDE=	pangox.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
