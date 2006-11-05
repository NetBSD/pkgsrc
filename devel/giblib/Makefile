# $NetBSD: Makefile,v 1.21 2006/11/05 17:49:33 joerg Exp $

DISTNAME=		giblib-1.2.4
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		http://linuxbrit.co.uk/downloads/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	giblib.pc.in
USE_LIBTOOL=		YES

.include "../../graphics/imlib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
