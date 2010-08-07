# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 02:25:03 obache Exp $
#

DISTNAME=	ibus-handwrite-2.1.0
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus-handwrite.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-handwrite/
COMMENT=	Handwrite recognizer for ibus
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	zinnia-tomoe-[0-9]*:../../inputmethod/zinnia-tomoe

FIND_PREFIX:=	ZINNIA_TOMOE_DIR=zinnia-tomoe
.include "../../mk/find-prefix.mk"

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-zinnia
CONFIGURE_ARGS+=	--with-zinnia-tomoe=${ZINNIA_TOMOE_DIR}/lib/zinnia/model/tomoe

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
