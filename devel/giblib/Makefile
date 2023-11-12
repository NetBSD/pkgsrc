# $NetBSD: Makefile,v 1.40 2023/11/12 13:20:59 wiz Exp $

DISTNAME=		giblib-1.2.4
PKGREVISION=		19
CATEGORIES=		devel
MASTER_SITES=		http://linuxbrit.co.uk/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://linuxbrit.co.uk/giblib/
COMMENT=		Programming utility library
LICENSE=		mit

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	giblib.pc.in
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

.include "../../graphics/imlib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
