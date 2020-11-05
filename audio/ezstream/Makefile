# $NetBSD: Makefile,v 1.10 2020/11/05 09:07:24 ryoon Exp $
#

DISTNAME=		ezstream-0.6.0
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://downloads.us.xiph.org/releases/ezstream/
LICENSE=		gnu-gpl-v2

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
