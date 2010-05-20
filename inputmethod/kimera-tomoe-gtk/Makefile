# $NetBSD: Makefile,v 1.1.1.1 2010/05/20 07:48:09 obache Exp $
#

DISTNAME=	kimera-tomoe-gtk-0.5
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=kimera/24906/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://kimera.sourceforge.jp/
COMMENT=	Kimera helper program for Tomoe
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	kimera-[0-9]*:../../inputmethod/kimera

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		libtomoe
SUBST_STAGE.libtomoe=	pre-configure
SUBST_FILES.libtomoe=	configure
SUBST_SED.libtomoe=	-e 's/libtomoe-gtk/tomoe-gtk/g'

.include "../../inputmethod/tomoe-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
