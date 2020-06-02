# $NetBSD: Makefile,v 1.35 2020/06/02 08:23:09 adam Exp $

DISTNAME=	gmpc-lyricwiki-11.8.16
PKGREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/11.8/

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
