# $NetBSD: Makefile,v 1.1 2018/10/03 20:09:00 tnn Exp $

DISTNAME=	hivex-1.3.15
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
CONFIGURE_ARGS+=	--disable-ocaml
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--without-readline

REPLACE_SH+=		sh/hivexget

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
