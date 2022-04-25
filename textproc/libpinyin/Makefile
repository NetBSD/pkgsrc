# $NetBSD: Makefile,v 1.10 2022/04/25 09:13:52 tnn Exp $

DISTNAME=	libpinyin-2.6.0
PKGREVISION=	1
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

.for os in Darwin SunOS
BUILDLINK_TRANSFORM.${os}+=	rm:-Wl,--version-script=./libpinyin.ver
BUILDLINK_TRANSFORM.${os}+=	rm:-Wl,--version-script=./libzhuyin.ver
.endfor

.include "../../databases/db4/buildlink3.mk"
BUILDLINK_TRANSFORM+=	l:db:db4
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
