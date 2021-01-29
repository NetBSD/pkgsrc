# $NetBSD: Makefile,v 1.22 2021/01/29 18:33:09 scole Exp $

DISTNAME=	libdatrie-0.2.13
CATEGORIES=	devel
MASTER_SITES=	https://linux.thai.net/pub/thailinux/software/libthai/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linux.thai.net/~thep/datrie/datrie.html
COMMENT=	Implementation of Double-Array Trie
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc
CONFIGURE_ENV+=		ICONV_LIBS=${BUILDLINK_LDADD.iconv:Q}
PKGCONFIG_OVERRIDE+=	datrie-0.2.pc.in
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
