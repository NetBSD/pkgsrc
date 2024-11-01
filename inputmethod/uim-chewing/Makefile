# $NetBSD: Makefile,v 1.28 2024/11/01 00:52:25 wiz Exp $
#

DISTNAME=	uim-chewing-0.1.0
PKGREVISION=	24
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
