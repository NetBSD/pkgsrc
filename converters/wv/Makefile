# $NetBSD: Makefile,v 1.56 2006/09/09 02:41:56 obache Exp $

DISTNAME=	wv-1.2.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://wvware.sourceforge.net/
COMMENT=	Library and executables to access Microsoft Word files

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libwmf=${BUILDLINK_PREFIX.libwmf}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}

PKGCONFIG_OVERRIDE+=	wv-1.0.pc.in

MAKE_FILE=		GNUmakefile

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
