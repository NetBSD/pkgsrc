# $NetBSD: Makefile,v 1.32 2003/12/13 23:45:12 xtraeme Exp $
#

DISTNAME=		wv-1.0.0
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		adam@NetBSD.org
HOMEPAGE=		http://wvware.sourceforge.net/
COMMENT=		Library and executables to access Microsoft Word files

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/wv-1.0.pc.in

MAKEFILE=		GNUmakefile

CONFIGURE_ARGS+=	--with-libwmf=${BUILDLINK_PREFIX.libwmf}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/libwmf/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
