# $NetBSD: Makefile,v 1.57 2026/09/27 11:37:17 tnn Exp $

DISTNAME=		scim-sinhala-0.1.0
PKGREVISION=		52
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_OSDN:=scim-imengine/16666/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://osdn.jp/projects/scim-imengine/
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
