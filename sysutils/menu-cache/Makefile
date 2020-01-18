# $NetBSD: Makefile,v 1.5 2020/01/18 23:35:18 rillig Exp $
#

DISTNAME=	menu-cache-1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxde.sourceforge.net/
COMMENT=	Cache for freedesktop.org menu spec
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	share/doc/menu-cache
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libmenu-cache/libmenu-cache.pc.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/menu-cache/

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libfm-extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
