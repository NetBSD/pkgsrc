# $NetBSD: Makefile,v 1.3 2014/08/10 02:30:00 obache Exp $

DISTNAME=	ibus-kkc-1.5.21
CATEGORIES=	inputmethod japanese
MASTER_SITES=	https://bitbucket.org/libkkc/ibus-kkc/downloads/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://bitbucket.org/libkkc/ibus-kkc/
COMMENT=	Japanese KKC input method for ibus
LICENSE=	gnu-gpl-v2

DEPENDS+=	skk-jisyo-[0-9]*:../../inputmethod/skk-jisyo
DEPENDS+=	libkkc-data-[0-9]*:../../misc/libkkc-data

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

FIND_PREFIX:=	SKK_JISYO_DIR=skk-jisyo
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--with-skkdic=${SKK_JISYO_DIR}/share/skk

.include "../../converters/libkkc/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
