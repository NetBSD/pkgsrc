# $NetBSD: Makefile,v 1.10 2012/09/12 00:24:35 asau Exp $
#

DISTNAME=	gmpc-tagedit-0.20.0
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/0.20.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_TAGEDIT
COMMENT=	GMPC plugin for editing song tags
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake intltool pkg-config msgfmt

.include "../../audio/gmpc/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/gob2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
