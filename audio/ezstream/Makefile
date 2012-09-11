# $NetBSD: Makefile,v 1.5 2012/09/11 23:59:31 asau Exp $
#

DISTNAME=		ezstream-0.5.4
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://downloads.us.xiph.org/releases/ezstream/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.icecast.org/ezstream.php
COMMENT=		Streamming client of mp3 and oggvorbis for icecast

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
REPLACE_SH=		examples/meta.sh examples/play.sh

.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
