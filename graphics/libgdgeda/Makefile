# $NetBSD: Makefile,v 1.11 2002/03/13 17:37:12 fredb Exp $
#

DISTNAME=		libgdgeda-1.8
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

DEPENDS+=		png>=1.2.1:../../graphics/png

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CPPFLAGS+=		-I${PREFIX}/include

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
