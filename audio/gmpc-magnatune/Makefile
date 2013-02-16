# $NetBSD: Makefile,v 1.19 2013/02/16 11:20:11 wiz Exp $
#

DISTNAME=	gmpc-magnatune-0.20.0
PKGREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/0.20.0/ \
		${MASTER_SITE_SOURCEFORGE:=musicpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_MAGNATUNE
COMMENT=	Magnatune plugin for GMPC
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool msgfmt pkg-config

.include "../../audio/gmpc/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
