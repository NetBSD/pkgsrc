# $NetBSD: Makefile,v 1.9 2004/01/03 18:49:38 reed Exp $
#

DISTNAME=		giblib-1.2.3
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.linuxbrit.co.uk/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/imlib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
