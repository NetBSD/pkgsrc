# $NetBSD: Makefile,v 1.36 2012/10/03 00:20:18 asau Exp $
#

DISTNAME=		wv2-0.2.3
PKGREVISION=		11
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://wvware.sourceforge.net/
COMMENT=		Library to access Microsoft Word files

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

# DragonFly's iconv(3) doesn't pass the configure check
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly"
USE_GNU_ICONV=		yes
.endif

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
