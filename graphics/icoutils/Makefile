# $NetBSD: Makefile,v 1.1 2018/01/01 07:08:27 ryoon Exp $

DISTNAME=	icoutils-0.32.2
CATEGORIES=	graphics
MASTER_SITES=	http://savannah.nongnu.org/download/icoutils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/icoutils/
COMMENT=	Tools for Microsoft Windows icon and cursor files
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
