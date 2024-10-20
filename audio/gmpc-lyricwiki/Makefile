# $NetBSD: Makefile,v 1.52 2024/10/20 14:03:22 wiz Exp $

DISTNAME=	gmpc-lyricwiki-11.8.16
PKGREVISION=	30
CATEGORIES=	audio
MASTER_SITES=	https://download.sarine.nl/Programs/gmpc/11.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_LYRICWIKI
COMMENT=	Lyrics plugin for GMPC using Lyricwiki
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config msgfmt

.include "../../audio/gmpc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
