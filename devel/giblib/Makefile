# $NetBSD: Makefile,v 1.18 2006/02/05 23:08:42 joerg Exp $

DISTNAME=		giblib-1.2.4
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.linuxbrit.co.uk/downloads/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://www.linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	giblib.pc.in
USE_LIBTOOL=		YES

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
