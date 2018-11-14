# $NetBSD: Makefile,v 1.36 2018/11/14 22:21:54 kleink Exp $
#

DISTNAME=		scim-tomoe-0.6.0
PKGREVISION=		32
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tomoe.osdn.jp/
COMMENT=		SCIM IMEngine module for Tomoe
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../inputmethod/tomoe-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
