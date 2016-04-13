# $NetBSD: Makefile,v 1.17 2016/04/13 10:10:25 wiz Exp $

DISTNAME=	atkmm-2.24.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	C++ bindings for atk
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

CONFLICTS+=	gtkmm<2.22.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake perl pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	atk/atkmm.pc.in

CXXFLAGS+=		-std=c++11

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
