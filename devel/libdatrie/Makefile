# $NetBSD: Makefile,v 1.21 2021/01/01 21:49:39 scole Exp $

DISTNAME=	libdatrie-0.2.12
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlwg/}
GITHUB_TAG=	f1479aaab1b877f305297bdb12fadc280a48cdd6

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linux.thai.net/~thep/datrie/datrie.html
COMMENT=	Implementation of Double-Array Trie
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake gm4 pkg-config sh aclocal autoconf autoreconf automake

CONFIGURE_ENV+=		ICONV_LIBS=${BUILDLINK_LDADD.iconv:Q}
PKGCONFIG_OVERRIDE+=	datrie-0.2.pc.in
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
