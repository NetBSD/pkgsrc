# $NetBSD: Makefile,v 1.34 2013/06/04 22:15:51 tron Exp $

DISTNAME=		giblib-1.2.4
PKGREVISION=		15
CATEGORIES=		devel
MASTER_SITES=		http://linuxbrit.co.uk/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	giblib.pc.in
USE_LIBTOOL=		YES

.include "../../graphics/imlib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
