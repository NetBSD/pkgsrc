# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 13:57:09 rh Exp $
#

DISTNAME=	gnome-vfs-0.4.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gnome-vfs/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	GConf-*:../../devel/GConf

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
