# $NetBSD: Makefile,v 1.18 2001/04/24 18:33:29 rh Exp $

DISTNAME=		gtop-1.0.13
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtop/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME system monitor - top like, memory graphs, process viewer

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome-core>1.4.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.12:../../devel/libgtop

OSVERSION_SPECIFIC=	YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_LIBINTL=		YES

GNU_CONFIGURE=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		LOCALEDIR=${PKGLOCALEDIR}
CFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
