# $NetBSD: Makefile,v 1.11 2012/10/03 00:02:40 asau Exp $
#

DISTNAME=	meanwhile-1.0.2
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=meanwhile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://meanwhile.sourceforge.net/
COMMENT=	Lotus SameTime compatible chat protocol

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+= --disable-doxygen

CHECK_WRKREF_SKIP+=	share/doc/meanwhile-doc-1.0.2/samples/build

PKGCONFIG_OVERRIDE+=	meanwhile.pc.in

.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
