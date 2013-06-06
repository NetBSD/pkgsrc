# $NetBSD: Makefile,v 1.26 2013/06/06 12:54:37 wiz Exp $
#

DISTNAME=	ibus-handwrite-2.1.4
PKGREVISION=	15
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus-handwrite.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-handwrite/
COMMENT=	Handwrite recognizer for ibus
LICENSE=	gnu-gpl-v3

DEPENDS+=	zinnia-tomoe-[0-9]*:../../inputmethod/zinnia-tomoe

FIND_PREFIX:=	ZINNIA_TOMOE_DIR=zinnia-tomoe
.include "../../mk/find-prefix.mk"

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-zinnia
CONFIGURE_ARGS+=	--with-zinnia-tomoe=${ZINNIA_TOMOE_DIR}/lib/zinnia/model/tomoe

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
