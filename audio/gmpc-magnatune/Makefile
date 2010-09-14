# $NetBSD: Makefile,v 1.2 2010/09/14 11:01:21 wiz Exp $
#

DISTNAME=		gmpc-magnatune-0.20.0
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://download.sarine.nl/Programs/gmpc/0.20.0/ \
			${MASTER_SITE_SOURCEFORGE:=musicpd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gmpc.wikia.com/wiki/GMPC_PLUGIN_MAGNATUNE
COMMENT=		Magnatune plugin for GMPC
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config

.include "../../audio/gmpc/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
