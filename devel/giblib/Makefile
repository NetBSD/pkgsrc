# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:27 tv Exp $

DISTNAME=		giblib-1.2.4
PKGREVISION=		1
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
