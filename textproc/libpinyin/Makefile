# $NetBSD: Makefile,v 1.15 2026/09/29 06:07:51 wiz Exp $

DISTNAME=	libpinyin-2.8.1
PKGREVISION=	4
CATEGORIES=	textproc chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=libpinyin/}
GITHUB_PROJECT=	libpinyin
GITHUB_RELEASE=	${PKGVERSION_NOREV}

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
