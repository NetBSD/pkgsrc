# $NetBSD: Makefile,v 1.44 2020/08/17 20:19:19 leot Exp $
#

DISTNAME=	uim-tomoe-gtk-0.6.0
PKGREVISION=	37
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tomoe.osdn.jp/
COMMENT=	UIM helper program for Tomoe
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../inputmethod/tomoe/buildlink3.mk"
.include "../../inputmethod/tomoe-gtk/buildlink3.mk"
.include "../../inputmethod/uim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
