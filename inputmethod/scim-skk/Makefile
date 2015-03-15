# $NetBSD: Makefile,v 1.23 2015/03/15 17:25:55 hiramatsu Exp $
#

DISTNAME=		scim-skk-0.5.2
PKGREVISION=		20
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=scim-imengine/18121/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://scim-imengine.sourceforge.jp/
COMMENT=		SCIM IMEngine module for skk
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c++ c
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
