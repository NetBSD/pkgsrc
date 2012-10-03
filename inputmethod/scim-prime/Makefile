# $NetBSD: Makefile,v 1.13.2.1 2012/10/03 12:08:26 spz Exp $
#

DISTNAME=		scim-prime-1.0.1
PKGREVISION=		12
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=scim-imengine/29156/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://scim-imengine.sourceforge.jp/
COMMENT=		SCIM IMEngine module for PRIME
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_VERSION_SUPPORTED= 18

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/prime/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
