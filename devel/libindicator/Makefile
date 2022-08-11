# $NetBSD: Makefile,v 1.16 2022/08/11 05:08:12 gutteridge Exp $

DISTNAME=	libindicator-12.10.1
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/libindicator/12.10/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/libindicator
COMMENT=	GTK+3 symbols and convience functions for indicators
LICENSE=	gnu-gpl-v3

CONFLICTS+=	libindicator3-[0-9]*
SUPERSEDES+=	libindicator3-[0-9]*

EXTRACT_USING=	gtar
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

INSTALL_DIRS=	libindicator

BUILDLINK_TRANSFORM+=	rm:-Werror
PKGCONFIG_OVERRIDE+=	libindicator/indicator-0.4.pc.in.in
PKGCONFIG_OVERRIDE+=	libindicator/indicator3-0.4.pc.in.in

CONFIGURE_ARGS+=	--with-gtk=3

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
