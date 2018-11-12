# $NetBSD: Makefile,v 1.4 2018/11/12 16:10:26 jaapb Exp $

DISTNAME=	hivex-1.3.15
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://download.libguestfs.org/hivex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libguestfs.org/
COMMENT=	Library for reading Windows Registry "hive" files
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=		bsdtar
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	hivex.pc.in

CONFIGURE_ARGS+=	--disable-nls

REPLACE_SH+=		sh/hivexget

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	tools
.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	ac_cv_func_open_memstream=no
.else
PLIST.tools=yes
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
