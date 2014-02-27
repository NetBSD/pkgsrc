# $NetBSD: Makefile,v 1.14 2014/02/27 12:45:24 obache Exp $

DISTNAME=	libthai-0.1.20
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/ \
		ftp://linux.thai.net/pub/ThaiLinux/software/libthai/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/libthai
COMMENT=	Thai language support routines
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

PKGCONFIG_OVERRIDE+=	libthai.pc.in

TEST_TARGET=	check

.include "../../devel/libdatrie/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
