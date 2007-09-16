# $NetBSD: Makefile,v 1.2 2007/09/16 20:55:31 joerg Exp $
#

DISTNAME=	libmms-0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmms/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://sourceforge.net/projects/libmms
COMMENT=	Library for parsing mms:// and mmsh:// type network streams

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

PKGCONFIG_OVERRIDE+=	pkgconfig/libmms.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
