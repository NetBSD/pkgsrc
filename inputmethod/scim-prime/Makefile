# $NetBSD: Makefile,v 1.25 2015/04/25 14:23:25 tnn Exp $
#

DISTNAME=		scim-prime-1.0.1
PKGREVISION=		21
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=scim-imengine/29156/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://scim-imengine.sourceforge.jp/
COMMENT=		SCIM IMEngine module for PRIME
LICENSE=		gnu-gpl-v2

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
