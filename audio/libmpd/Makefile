# $NetBSD: Makefile,v 1.15 2012/09/12 00:24:43 asau Exp $
#

DISTNAME=		libmpd-0.20.0
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		http://download.sarine.nl/Programs/gmpc/0.20.0/ \
			${MASTER_SITE_SOURCEFORGE:=musicpd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gmpc.wikia.com/?title=Libmpd
COMMENT=		Library to access mpd (musicpd)
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libmpd.pc.in
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
