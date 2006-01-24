# $NetBSD: Makefile,v 1.17 2006/01/24 07:31:59 wiz Exp $
#

DISTNAME=		wv2-0.2.2
PKGREVISION=		3
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://wvware.sourceforge.net/
COMMENT=		Library to access Microsoft Word files

USE_GNU_ICONV=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
