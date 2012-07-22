# $NetBSD: Makefile,v 1.3 2012/07/22 13:08:05 obache Exp $
#

DISTNAME=	libskk-0.0.13
CATEGORIES=	inputmethod
MASTER_SITES=	http://cloud.github.com/downloads/ueno/libskk/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/ueno/libskk/
COMMENT=	Library to deal with Japnese kana-to-kanji conversion method
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libskk/libskk.pc.in

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
