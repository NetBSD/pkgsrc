# $NetBSD: Makefile,v 1.90 2020/06/02 08:22:33 adam Exp $

DISTNAME=	wv-1.2.9
PKGREVISION=	15
CATEGORIES=	converters
MASTER_SITES=	http://www.abiword.com/downloads/wv/${PKGVERSION_NOREV}/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://wvware.sourceforge.net/
COMMENT=	Library and executables to access Microsoft Word files

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libwmf=${BUILDLINK_PREFIX.libwmf}
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

PKGCONFIG_OVERRIDE+=	wv-1.0.pc.in

MAKE_FILE=		GNUmakefile

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
