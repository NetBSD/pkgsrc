# $NetBSD: Makefile,v 1.2 2000/02/09 20:20:55 tron Exp $
#

DISTNAME=		libgdgeda-1.6
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/

DEPENDS+=		png>=1.0.3:../../graphics/png

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
