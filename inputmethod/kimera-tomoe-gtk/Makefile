# $NetBSD: Makefile,v 1.34 2019/07/21 22:25:10 wiz Exp $
#

DISTNAME=	kimera-tomoe-gtk-0.5
PKGREVISION=	29
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=kimera/24906/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kimera.osdn.jp/
COMMENT=	Kimera helper program for Tomoe
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	kimera-[0-9]*:../../inputmethod/kimera

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config

SUBST_CLASSES+=		libtomoe
SUBST_STAGE.libtomoe=	pre-configure
SUBST_FILES.libtomoe=	configure
SUBST_SED.libtomoe=	-e 's/libtomoe-gtk/tomoe-gtk/g'

.include "../../inputmethod/tomoe-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
