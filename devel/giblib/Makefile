# $NetBSD: Makefile,v 1.13 2004/09/20 21:56:49 snj Exp $

DISTNAME=		giblib-1.2.4
CATEGORIES=		devel
MASTER_SITES=		http://www.linuxbrit.co.uk/downloads/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://www.linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	giblib.pc.in
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

.include "../../graphics/imlib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
