# $NetBSD: Makefile,v 1.1.1.1 2000/01/02 17:33:02 rh Exp $
#

DISTNAME=		libgdgeda-1.6
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/

DEPENDS+=		png-*:../../graphics/png

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
