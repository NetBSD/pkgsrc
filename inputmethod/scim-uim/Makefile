# $NetBSD: Makefile,v 1.41 2022/08/11 05:08:54 gutteridge Exp $
#

DISTNAME=		scim-uim-0.2.0
PKGREVISION=		37
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/scim-im/scim
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
