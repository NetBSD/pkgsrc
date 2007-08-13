# $NetBSD: Makefile,v 1.1.1.1 2007/08/13 05:29:27 dan Exp $
#

DISTNAME=	meanwhile-1.0.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=meanwhile/}

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://meanwhile.sourceforge.net/
COMMENT=	Lotus SameTime compatible chat protocol

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+= --disable-doxygen

PKGCONFIG_OVERRIDE+=	meanwhile.pc.in

.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
