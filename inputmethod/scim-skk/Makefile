# $NetBSD: Makefile,v 1.33 2018/11/14 22:21:53 kleink Exp $
#

DISTNAME=		scim-skk-0.5.2
PKGREVISION=		29
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_OSDN:=scim-imengine/18121/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://osdn.jp/projects/scim-imengine/
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
