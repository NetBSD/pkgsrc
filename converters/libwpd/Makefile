# $NetBSD: Makefile,v 1.30 2014/01/26 04:43:00 ryoon Exp $

DISTNAME=	libwpd-0.9.9
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents
LICENSE=	gnu-lgpl-v2.1

.include "../../mk/bsd.prefs.mk"
# OpenBSD's gcc 4.2.1 is not sufficient, and gcc46 is minimal pkgsrc gcc
# for OpenBSD. Avoid warning as error.
.if ${OPSYS} == "OpenBSD"
GCC_REQD+=		4.6
.endif

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwpd-0.9.pc.in libwpd-stream-0.9.pc.in

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-unused-private-field
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
