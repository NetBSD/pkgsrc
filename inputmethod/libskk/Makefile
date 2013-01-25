# $NetBSD: Makefile,v 1.6 2013/01/25 12:07:13 obache Exp $
#

DISTNAME=	libskk-1.0.0
CATEGORIES=	inputmethod
MASTER_SITES=	http://cloud.github.com/downloads/ueno/libskk/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/ueno/libskk/
COMMENT=	Library to deal with Japnese kana-to-kanji conversion method
LICENSE=	gnu-gpl-v3

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
