# $NetBSD: Makefile,v 1.10 2004/02/11 05:53:05 xtraeme Exp $
#

DISTNAME=		giblib-1.2.3
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		http://www.linuxbrit.co.uk/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
