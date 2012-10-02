# $NetBSD: Makefile,v 1.11 2012/10/02 17:10:31 tron Exp $
#

DISTNAME=	gmpc-last-fm-0.20.0
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/0.20.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/Last.fm
COMMENT=	GMPC plugin for fetching cover and artist art from last.fm
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config msgfmt

.include "../../audio/gmpc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
