# $NetBSD: Makefile,v 1.8 2021/02/20 13:39:46 ryoon Exp $

DISTNAME=	libpinyin-2.6.0
CATEGORIES=	textproc chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpinyin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libpinyin/libpinyin/
COMMENT=	Library to deal with pinyin
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-libzhuyin

PKGCONFIG_OVERRIDE+=	libpinyin.pc.in
PKGCONFIG_OVERRIDE+=	libzhuyin.pc.in

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--version-script=./libpinyin.ver
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./libpinyin.ver

.include "../../databases/db4/buildlink3.mk"
BUILDLINK_TRANSFORM+=	l:db:db4
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
