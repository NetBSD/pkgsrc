# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:45 jlam Exp $

DISTNAME=	ogle_gui-0.9.2
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	GUI for the Ogle DVD player

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--bindir=${PREFIX}/lib/ogle

GCC_REQD+=		2.95.3

LDFLAGS+=	${BUILDLINK_LDFLAGS.ogle}

.include "../../devel/binutils/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../multimedia/ogle/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
