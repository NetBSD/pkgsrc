# $NetBSD: Makefile,v 1.6 2001/02/17 17:42:13 wiz Exp $
#

DISTNAME=	gnome-vfs-0.4.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gnome-vfs/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME Virtual File System

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake
DEPENDS+=	GConf>=0.11:../../devel/GConf

USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	YES

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf && ${LOCALBASE}/bin/automake

.include "../../mk/bsd.pkg.mk"
