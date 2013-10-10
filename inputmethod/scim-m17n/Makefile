# $NetBSD: Makefile,v 1.25 2013/10/10 14:42:19 ryoon Exp $
#

DISTNAME=		scim-m17n-0.2.3
PKGREVISION=		23
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		SCIM IMEngine module for m17n-lib
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
