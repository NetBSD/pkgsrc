# $NetBSD: Makefile,v 1.7 2018/01/01 21:18:41 adam Exp $

DISTNAME=		vowpal_wabbit-8.2.0
PKGREVISION=		6
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=JohnLangford/}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://hunch.net/~vw/
COMMENT=		Vowpal Wabbit is a machine learning system
LICENSE=		gnu-lgpl-v2

GITHUB_PROJECT=		vowpal_wabbit

USE_TOOLS+=		autoconf automake autoreconf autoheader aclocal gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

AUTOCONF_REQD=		2.60
GNU_CONFIGURE=		yes

LIBTOOLIZE=		${PREFIX}/bin/libtoolize

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}

pre-configure:
	set -e; \
	cd ${WRKSRC}; \
	${LIBTOOLIZE} -f -c; \
	aclocal -I ./acinclude.d; \
	autoheader; \
	touch README; \
	automake -ac -Woverride; \
	autoconf

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
