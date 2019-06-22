# $NetBSD: Makefile,v 1.13 2019/06/22 11:52:31 nia Exp $

DISTNAME=	libmms-0.6.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmms/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://sourceforge.net/projects/libmms
COMMENT=	Library for parsing mms:// and mmsh:// type network streams
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CPPFLAGS.SunOS+=	-Du_int64_t=uint64_t -Du_int32_t=uint32_t -Du_int16_t=uint16_t

PKGCONFIG_OVERRIDE+=	pkgconfig/libmms.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
