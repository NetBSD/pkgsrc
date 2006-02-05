# $NetBSD: Makefile,v 1.10 2006/02/05 23:10:17 joerg Exp $

DISTNAME=	ogle_gui-0.9.2
PKGREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
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
