# $NetBSD: Makefile,v 1.8 2012/09/15 10:04:06 obache Exp $

DISTNAME=	atkmm-2.22.6
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	C++ bindings for atk
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

CONFLICTS+=	gtkmm<2.22.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		autoconf gmake perl pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	atkmm-2.22.1/atk/PaxHeaders.17805/atkmm.pc.in
PKGCONFIG_OVERRIDE+=	atkmm-2.22.1/atk/atkmm.pc.in

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
