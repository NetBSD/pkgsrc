# $NetBSD: Makefile,v 1.4 2011/04/21 15:06:04 hans Exp $
#

DISTNAME=		libmtp-1.0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libmtp/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://libmtp.sourceforge.net/
COMMENT=		Implementation of Media Transfer Protocol (MTP)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		HAVE_DOXYGEN=false

PKGCONFIG_OVERRIDE+=	libmtp.pc.in

REPLACE_SH=		hotplug.sh.in
REPLACE_SH+=		libmtp.sh.in

# XXX ?
LDFLAGS.FreeBSD+=	-liconv
LDFLAGS.SunOS=		-liconv
CPPFLAGS.SunOS=		-Du_int64_t=uint64_t -Du_int32_t=uint32_t

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
