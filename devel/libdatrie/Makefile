# $NetBSD: Makefile,v 1.13 2014/02/27 12:42:05 obache Exp $
#

DISTNAME=	libdatrie-0.2.8
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/ \
		ftp://linux.thai.net/pub/ThaiLinux/software/libthai/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/~thep/datrie/datrie.html
COMMENT=	Implementation of Double-Array Trie
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=	ICONV_LIBS=${BUILDLINK_LDADD.iconv:Q}

PKGCONFIG_OVERRIDE+=	datrie-0.2.pc.in

CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
