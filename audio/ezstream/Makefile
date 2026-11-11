# $NetBSD: Makefile,v 1.28 2026/11/11 11:51:45 wiz Exp $
#

DISTNAME=		ezstream-1.0.2
PKGREVISION=		16
CATEGORIES=		audio
MASTER_SITES=		https://downloads.xiph.org/releases/ezstream/
MASTER_SITES+=		https://ezstream.mrsserver.net/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.icecast.org/ezstream/
COMMENT=		Streaming client for Icecast
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake
REPLACE_SH=		examples/meta.sh examples/play.sh

.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
BUILDLINK_DEPMETHOD.check?=	build
.include "../../devel/check/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
