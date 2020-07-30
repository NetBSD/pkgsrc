# $NetBSD: Makefile,v 1.20 2020/07/30 01:56:16 scole Exp $

DISTNAME=	libdatrie-0.2.12
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/
MASTER_SITES+=	ftp://linux.thai.net/pub/ThaiLinux/software/libthai/
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
