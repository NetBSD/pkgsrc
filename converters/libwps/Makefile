# $NetBSD: Makefile,v 1.17 2015/01/16 09:08:38 wiz Exp $

DISTNAME=	libwps-0.3.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwps/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libwps.sourceforge.net/
COMMENT=	Library for importing Microsoft Works documents
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwps.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-unused-private-field -Wno-unused-const-variable
CWRAPPERS_APPEND.cxx+=	-Wno-unused-private-field -Wno-unused-const-variable
.endif

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
