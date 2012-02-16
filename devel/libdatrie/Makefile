# $NetBSD: Makefile,v 1.9 2012/02/16 18:46:51 hans Exp $
#

DISTNAME=	libdatrie-0.2.5
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/ \
		ftp://linux.thai.net/pub/ThaiLinux/software/libthai/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/~thep/datrie/datrie.html
COMMENT=	Implementation of Double-Array Trie
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

LIBS.SunOS+=	-liconv

PKGCONFIG_OVERRIDE+=	datrie-0.2.pc.in

CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
