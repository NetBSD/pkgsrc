# $NetBSD: Makefile,v 1.17 2020/01/18 23:30:32 rillig Exp $

DISTNAME=	libmtp-1.1.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmtp/}

MAINTAINER=	ku3@sl.aanet.ru
HOMEPAGE=	https://libmtp.sourceforge.net/
COMMENT=	Implementation of Media Transfer Protocol (MTP)
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		HAVE_DOXYGEN=false
PKGCONFIG_OVERRIDE+=	libmtp.pc.in

REPLACE_SH=		hotplug.sh.in
REPLACE_SH+=		libmtp.sh.in

LDFLAGS.FreeBSD+=	-liconv
LDFLAGS.SunOS=		-liconv

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
