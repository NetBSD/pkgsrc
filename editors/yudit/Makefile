# $NetBSD: Makefile,v 1.17 2005/08/12 13:47:31 adam Exp $

DISTNAME=	yudit-2.7.8
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
