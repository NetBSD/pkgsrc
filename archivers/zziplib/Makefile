# $NetBSD: Makefile,v 1.9 2005/10/23 20:58:58 rillig Exp $
#

DISTNAME=	zziplib-0.10.82
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=zziplib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://zziplib.sourceforge.net/
COMMENT=	Library for ZIP archive handling

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--disable-builddir

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
