# $NetBSD: Makefile,v 1.1.1.1 2002/09/20 10:55:39 rh Exp $
#

DISTNAME=		giblib-1.2.2
CATEGORIES=		devel
MASTER_SITES=		http://www.linuxbrit.co.uk/downloads/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.linuxbrit.co.uk/giblib/
COMMENT=		programming utility library

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/imlib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
