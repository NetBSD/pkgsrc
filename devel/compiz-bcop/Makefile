# $NetBSD: Makefile,v 1.1.1.1 2008/05/12 12:40:32 jmcneill Exp $
#

DISTNAME=	compiz-bcop-0.6.0
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Option code generator for compiz

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	bcop.pc.in

.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
