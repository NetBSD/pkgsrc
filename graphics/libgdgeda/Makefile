# $NetBSD: Makefile,v 1.9 2001/06/11 06:34:37 jlam Exp $
#

DISTNAME=		libgdgeda-1.6
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

DEPENDS+=		png>=1.0.11:../../graphics/png

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CPPFLAGS+=		-I${PREFIX}/include

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
