# $NetBSD: Makefile,v 1.30 2004/01/24 15:06:57 grant Exp $

DISTNAME=		gtop-1.0.13
PKGREVISION=		6
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtop/1.0/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME system monitor - top like, memory graphs, process viewer

BUILD_USES_MSGFMT=	YES

OSVERSION_SPECIFIC=	YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		LOCALEDIR=${PKGLOCALEDIR}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgtop/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
