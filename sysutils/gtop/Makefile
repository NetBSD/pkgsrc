# $NetBSD: Makefile,v 1.36 2004/04/26 05:44:33 snj Exp $

DISTNAME=		gtop-1.0.13
PKGREVISION=		8
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtop/1.0/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME system monitor - top like, memory graphs, process viewer

BUILD_USES_MSGFMT=	YES

OSVERSION_SPECIFIC=	YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		LOCALEDIR=${PKGLOCALEDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
