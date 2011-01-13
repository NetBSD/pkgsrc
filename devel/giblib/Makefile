# $NetBSD: Makefile,v 1.27 2011/01/13 13:36:16 wiz Exp $

DISTNAME=		giblib-1.2.4
PKGREVISION=		9
CATEGORIES=		devel
MASTER_SITES=		http://linuxbrit.co.uk/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	giblib.pc.in
USE_LIBTOOL=		YES

.include "../../graphics/imlib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
