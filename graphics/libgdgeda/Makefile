# $NetBSD: Makefile,v 1.3 2000/03/21 22:40:53 tron Exp $
#

DISTNAME=		libgdgeda-1.6
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/

DEPENDS+=		png>=1.0.6:../../graphics/png

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
