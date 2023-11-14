# $NetBSD: Makefile,v 1.47 2023/11/14 14:02:20 wiz Exp $
#

DISTNAME=		scim-anthy-1.2.7
PKGREVISION=		41
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_OSDN:=scim-imengine/37309/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://osdn.jp/projects/scim-imengine/
COMMENT=		SCIM IMEngine module for anthy
LICENSE=		gnu-gpl-v2

DEPENDS+=		kasumi>=0.6:../../inputmethod/kasumi

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
