# $NetBSD: Makefile,v 1.24 2024/05/29 16:33:51 adam Exp $
#

DISTNAME=		gift-gnutella-0.0.11
PKGREVISION=		11
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gift/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gift.sourceforge.net/
COMMENT=		Gnutella plugin for giFT

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

SHLIBTOOL_OVERRIDE=	# empty
CONFIGURE_ARGS+=	--with-libxml=${BUILDLINK_PREFIX.libxml2}

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
