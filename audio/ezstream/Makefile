# $NetBSD: Makefile,v 1.3 2012/02/15 21:23:25 hans Exp $
#

DISTNAME=		ezstream-0.5.4
CATEGORIES=		audio
MASTER_SITES=		http://downloads.us.xiph.org/releases/ezstream/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.icecast.org/ezstream.php
COMMENT=		Streamming client of mp3 and oggvorbis for icecast

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKG_DESTDIR_SUPPORT=	user-destdir
REPLACE_SH=		examples/meta.sh examples/play.sh

.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
