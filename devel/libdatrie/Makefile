# $NetBSD: Makefile,v 1.1.1.1 2008/02/11 02:11:24 obache Exp $
#

DISTNAME=	libdatrie-0.1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://linux.thai.net/pub/ThaiLinux/software/libthai/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/~thep/datrie/datrie.html
COMMENT=	Implementation of Double-Array Trie

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	datrie.pc.in

CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../mk/bsd.pkg.mk"
