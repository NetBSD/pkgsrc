# $NetBSD: Makefile,v 1.9 2012/05/15 07:18:04 obache Exp $
#

DISTNAME=	meanwhile-1.0.2
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=meanwhile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://meanwhile.sourceforge.net/
COMMENT=	Lotus SameTime compatible chat protocol

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+= --disable-doxygen

CHECK_WRKREF_SKIP+=	share/doc/meanwhile-doc-1.0.2/samples/build

PKGCONFIG_OVERRIDE+=	meanwhile.pc.in

.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
