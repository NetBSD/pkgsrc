# $NetBSD: Makefile,v 1.16 2012/09/15 10:03:40 obache Exp $
#

DISTNAME=		libmpd-0.20.0
PKGREVISION=		5
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
