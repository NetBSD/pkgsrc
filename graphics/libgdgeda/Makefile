# $NetBSD: Makefile,v 1.7 2001/03/04 09:06:12 tron Exp $
#

DISTNAME=		libgdgeda-1.6
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

DEPENDS+=		png>1.0.9:../../graphics/png

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
