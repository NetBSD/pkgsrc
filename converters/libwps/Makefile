# $NetBSD: Makefile,v 1.11 2014/05/12 12:09:43 ryoon Exp $

DISTNAME=	libwps-0.2.4
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
PKGCONFIG_OVERRIDE+=	libwps-0.2.pc.in

.include "../../mk/bsd.prefs.mk"
# GCC 4.5 or later may be required, and gcc45 is not provided for OpenBSD
.if ${OPSYS} == "OpenBSD"
GCC_REQD+=      4.6
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-unused-private-field -Wno-unused-const-variable
.endif

.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
