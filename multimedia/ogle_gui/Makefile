# $NetBSD: Makefile,v 1.13 2007/05/13 14:55:32 veego Exp $

DISTNAME=	ogle_gui-0.9.2
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	GUI for the Ogle DVD player

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--bindir=${PREFIX}/lib/ogle

GCC_REQD+=		2.95.3

.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../multimedia/ogle/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
