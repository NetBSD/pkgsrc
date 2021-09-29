# $NetBSD: Makefile,v 1.19 2021/09/29 19:00:59 adam Exp $

DISTNAME=		vowpal_wabbit-8.2.0
PKGREVISION=		16
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=JohnLangford/}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		https://hunch.net/~vw/
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
LDFLAGS.SunOS+=		-lsocket -lnsl

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
