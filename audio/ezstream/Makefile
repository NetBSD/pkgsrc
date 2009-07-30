# $NetBSD: Makefile,v 1.1.1.1 2009/07/30 16:31:24 drochner Exp $
#

DISTNAME=		ezstream-0.5.4
CATEGORIES=		audio
MASTER_SITES=		http://downloads.us.xiph.org/releases/ezstream/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.icecast.org/ezstream.php
COMMENT=		Streamming client of mp3 and oggvorbis for icecast

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
