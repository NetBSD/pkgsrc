# $NetBSD: Makefile,v 1.11 2020/11/26 15:56:07 nia Exp $
#

DISTNAME=		ezstream-0.6.0
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://downloads.us.xiph.org/releases/ezstream/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.icecast.org/ezstream/
COMMENT=		Streaming client for Icecast
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
REPLACE_SH=		examples/meta.sh examples/play.sh

.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
