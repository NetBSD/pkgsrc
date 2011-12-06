# $NetBSD: Makefile,v 1.10 2011/12/06 11:21:11 obache Exp $
#

DISTNAME=	libthai-0.1.16
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/ \
		ftp://linux.thai.net/pub/ThaiLinux/software/libthai/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/libthai
COMMENT=	Thai language support routines
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libthai.pc.in

CONFIGURE_ARGS+=	--disable-doxygen-doc

TEST_TARGET=	check

.include "../../devel/libdatrie/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
