# $NetBSD: Makefile,v 1.23 2004/01/03 18:49:44 reed Exp $

DISTNAME=	ogle_gui-0.9.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	GUI for the Ogle DVD player

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--bindir=${PREFIX}/lib/ogle

GCC_REQD=		2.95.3

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LDFLAGS+=	${BUILDLINK_LDFLAGS.ogle}

.include "../../devel/binutils/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/ogle/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
