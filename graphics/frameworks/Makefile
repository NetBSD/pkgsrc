# $NetBSD: Makefile,v 1.1.1.1 2009/01/10 21:08:14 jmcneill Exp $
#

DISTNAME=	frameworks-0.3.7
CATEGORIES=	graphics
MASTER_SITES=	http://frameworks.polycrystal.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://frameworks.polycrystal.org/release/
COMMENT=	Stop-motion animation frame capture software

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake autoconf

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
