# $NetBSD: Makefile,v 1.38 2021/12/08 16:05:18 adam Exp $
#

DISTNAME=		scim-sinhala-0.1.0
PKGREVISION=		34
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_OSDN:=scim-imengine/16666/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://osdn.jp/projects/scim-imengine/
COMMENT=		SCIM IMEngine module for Sinhala
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
