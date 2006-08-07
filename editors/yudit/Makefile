# $NetBSD: Makefile,v 1.19 2006/08/07 23:54:17 wiz Exp $

DISTNAME=	yudit-2.8.1
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
