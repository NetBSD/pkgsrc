# $NetBSD: Makefile,v 1.10 2012/10/23 17:18:34 asau Exp $
#

DISTNAME=	libmms-0.6
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmms/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://sourceforge.net/projects/libmms
COMMENT=	Library for parsing mms:// and mmsh:// type network streams
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CPPFLAGS.SunOS+=	-Du_int64_t=uint64_t -Du_int32_t=uint32_t -Du_int16_t=uint16_t

PKGCONFIG_OVERRIDE+=	pkgconfig/libmms.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
