# $NetBSD: Makefile,v 1.42 2018/11/12 03:52:21 ryoon Exp $
#

DISTNAME=	ibus-handwrite-3.0.0
PKGREVISION=	8
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/microcai/ibus-handwrite/releases/download/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/ibus-handwrite/
COMMENT=	Handwrite recognizer for ibus
LICENSE=	gnu-gpl-v3

DEPENDS+=	zinnia-tomoe-[0-9]*:../../inputmethod/zinnia-tomoe

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-zinnia
CONFIGURE_ARGS+=	--with-zinnia-tomoe=${LOCALBASE}/lib/zinnia/model/tomoe

SUBST_CLASSES+=		locale_dir
SUBST_STAGE.locale_dir=	pre-configure
SUBST_FILES.locale_dir=	src/main.c
SUBST_VARS.locale_dir=	_PKGLOCALEDIR

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
