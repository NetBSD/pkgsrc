# $NetBSD: Makefile,v 1.1.1.1 2005/08/19 16:05:03 drochner Exp $
#

DISTNAME=		pslib-0.2.6
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pslib/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pslib.sourceforge.net/
COMMENT=		C-library to create PostScript files

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libps.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
