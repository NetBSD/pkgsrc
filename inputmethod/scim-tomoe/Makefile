# $NetBSD: Makefile,v 1.47 2022/08/11 05:08:54 gutteridge Exp $
#

DISTNAME=		scim-tomoe-0.6.0
PKGREVISION=		42
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://tomoe.osdn.jp/
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
