# $NetBSD: Makefile,v 1.4 2010/06/03 08:16:09 obache Exp $
#

DISTNAME=	libmms-0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmms/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://sourceforge.net/projects/libmms
COMMENT=	Library for parsing mms:// and mmsh:// type network streams
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pkgconfig/libmms.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
