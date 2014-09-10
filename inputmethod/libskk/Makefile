# $NetBSD: Makefile,v 1.8 2014/09/10 09:34:45 obache Exp $
#

DISTNAME=	libskk-1.0.2
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/ueno/libskk/releases/download/${PKGVERSION_NOREV}/

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

.include "options.mk"

TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee0.8/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
