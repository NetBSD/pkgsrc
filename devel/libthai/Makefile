# $NetBSD: Makefile,v 1.1.1.1 2008/02/11 02:20:44 obache Exp $
#

DISTNAME=	libthai-0.1.9
CATEGORIES=	devel
MASTER_SITES=	ftp://linux.thai.net/pub/ThaiLinux/software/libthai/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/libthai
COMMENT=	Thai language support routines

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libthai.pc.in

CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../devel/libdatrie/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
