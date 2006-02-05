# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:24 joerg Exp $
#

DISTNAME=		gift-gnutella-0.0.9.2
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gift/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gift..sourceforge.net/
COMMENT=		Gnutella plugin for giFT

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

SHLIBTOOL_OVERRIDE=	libtool
CONFIGURE_ARGS+=	--with-libxml=${BUILDLINK_PREFIX.libxml2}

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
