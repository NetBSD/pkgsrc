# $NetBSD: Makefile,v 1.27 2024/05/29 16:33:12 adam Exp $
#

DISTNAME=	uim-chewing-0.1.0
PKGREVISION=	23
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://uim.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uim/uim
COMMENT=	Chewing im for uim
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

UIM_MODULES=	chewing
.include "../../inputmethod/uim/modules.mk"

.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../inputmethod/uim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
