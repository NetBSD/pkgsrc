# $NetBSD: Makefile,v 1.3 2011/04/22 13:42:28 obache Exp $

DISTNAME=	atkmm-2.22.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atkmm/2.22/}
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
