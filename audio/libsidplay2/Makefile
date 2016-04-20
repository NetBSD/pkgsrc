# $NetBSD: Makefile,v 1.8 2016/04/20 12:10:28 nros Exp $
#

DISTNAME=	sidplay-libs-2.1.1
PKGNAME=	libsidplay2-2.1.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sidplay2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sidplay2.sourceforge.net/
COMMENT=	Sidplay2 Library
LICENSE=	gnu-gpl-v2

OVERRIDE_DIRDEPTH=	3
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--includedir=${PREFIX:Q}/include/libsidplay2

.include "../../mk/bsd.pkg.mk"
