# $NetBSD: Makefile,v 1.52 2012/09/07 19:17:18 adam Exp $

DISTNAME=	aMule-2.2.6
PKGNAME=	${DISTNAME:S/aMule/amule/}
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amule/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tripledes@eslack.org
HOMEPAGE=	http://www.amule.org/
COMMENT=	Another Emule P2P client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		xmule-[0-9]*

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-wx-config=${BUILDLINK_PREFIX.wxGTK28}/bin/wx-config
CONFIGURE_ARGS+=	--with-crypto-prefix=${BUILDLINK_PREFIX.cryptopp}
CONFIGURE_ARGS+=	--with-language=all

.include "options.mk"

REPLACE_PERL=		src/libs/ec/file_generator.pl		\
			src/utils/scripts/kadnodescreate.pl	\
			src/utils/scripts/stats.pl		\
			src/utils/scripts/mldonkey_importer.pl	\
			src/utils/xas/xas.pl

LIBS+=			-lm	# for pow(3)

UNLIMIT_RESOURCES+=	datasize

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
