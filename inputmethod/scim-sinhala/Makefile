# $NetBSD: Makefile,v 1.7 2011/11/01 06:01:55 sbd Exp $
#

DISTNAME=		scim-sinhala-0.1.0
PKGREVISION=		6
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=scim-imengine/16666/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://scim-imengine.sourceforge.jp/
COMMENT=		SCIM IMEngine module for Sinhala
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
