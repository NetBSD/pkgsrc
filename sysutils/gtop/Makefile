# $NetBSD: Makefile,v 1.20 2002/10/19 10:54:57 rh Exp $

DISTNAME=		gtop-1.0.13
PKGREVISION=		1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtop/1.0/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME system monitor - top like, memory graphs, process viewer

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome-core>=1.4.0.4nb1:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.12nb2:../../devel/libgtop

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
