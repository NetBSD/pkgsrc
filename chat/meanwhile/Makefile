# $NetBSD: Makefile,v 1.15 2020/03/08 16:48:58 wiz Exp $
#

DISTNAME=	meanwhile-1.0.2
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=meanwhile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://meanwhile.sourceforge.net/
COMMENT=	Lotus SameTime compatible chat protocol

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-doxygen

CHECK_WRKREF_SKIP+=	share/doc/meanwhile-doc-1.0.2/samples/build

PKGCONFIG_OVERRIDE+=	meanwhile.pc.in

.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
