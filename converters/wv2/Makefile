# $NetBSD: Makefile,v 1.4 2004/02/14 17:21:35 jlam Exp $
#

DISTNAME=		wv2-0.2.1
PKGREVISION=		2
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://wvware.sourceforge.net/
COMMENT=		Library to access Microsoft Word files

USE_BUILDLINK2=		yes
USE_GNU_ICONV=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.libiconv}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
