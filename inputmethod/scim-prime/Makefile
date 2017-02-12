# $NetBSD: Makefile,v 1.30 2017/02/12 06:25:37 ryoon Exp $
#

DISTNAME=		scim-prime-1.0.1
PKGREVISION=		24
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_OSDN:=scim-imengine/29156/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://osdn.jp/projects/scim-imengine/
COMMENT=		SCIM IMEngine module for PRIME
LICENSE=		gnu-gpl-v2

RUBY_VERSIONS_ACCEPTED= 18

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
