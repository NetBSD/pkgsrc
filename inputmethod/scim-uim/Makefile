# $NetBSD: Makefile,v 1.20 2013/06/04 22:16:32 tron Exp $
#

DISTNAME=		scim-uim-0.2.0
PKGREVISION=		18
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		SCIM IMEngine module for UIM
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../inputmethod/scim/buildlink3.mk"
.include "../../inputmethod/uim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
