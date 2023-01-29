# $NetBSD: Makefile,v 1.14 2023/01/29 21:14:37 ryoon Exp $
#

DISTNAME=	agg-2.5
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.antigrain.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.antigrain.com/
COMMENT=	High Quality Rendering Engine for C++
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake msgfmt pkg-config aclocal autoheader \
		automake autoconf autoreconf
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libagg.pc.in

pre-configure:
	cd ${WRKSRC}; ${TOOLS_PATH.autoreconf} -vi

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX}/lib
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
