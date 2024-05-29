# $NetBSD: Makefile,v 1.69 2024/05/29 16:33:46 adam Exp $

DISTNAME=	ogle_gui-0.9.2
PKGREVISION=	56
CATEGORIES=	multimedia
#MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	GUI for the Ogle DVD player

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--bindir=${PREFIX}/lib/ogle
CONFIGURE_ARGS+=	--enable-gtk2

.include "../../devel/libglade/buildlink3.mk"
.include "../../multimedia/ogle/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
