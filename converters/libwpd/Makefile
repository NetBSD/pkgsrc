# $NetBSD: Makefile,v 1.47 2019/07/01 04:07:46 ryoon Exp $

DISTNAME=	libwpd-0.10.1
PKGREVISION=	9
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwpd.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"

# Include all buildlink3.mk before compiler.mk, as the buildlink dependencies
# may alter the compiler selection.
.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-unused-private-field
CWRAPPERS_APPEND.cxx+=	-Wno-unused-private-field
CWRAPPERS_APPEND.cxx+=	-Wno-unknown-warning-option
CWRAPPERS_APPEND.cxx+=	-Wno-tautological-type-limit-compare
.endif

.include "../../mk/bsd.pkg.mk"
