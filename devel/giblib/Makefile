# $NetBSD: Makefile,v 1.37 2020/11/24 17:10:43 nia Exp $

DISTNAME=		giblib-1.2.4
PKGREVISION=		16
CATEGORIES=		devel
MASTER_SITES=		http://linuxbrit.co.uk/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library
LICENSE=		mit

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	giblib.pc.in
USE_LIBTOOL=		YES

.include "../../graphics/imlib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
