# $NetBSD: Makefile,v 1.2 2006/06/09 15:24:09 minskim Exp $
#

DISTNAME=	sidplay-libs-2.1.1
PKGNAME=	libsidplay2-2.1.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sidplay2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sidplay2.sourceforge.net/
COMMENT=	Sidplay2 Library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c++

CONFIGURE_ARGS+=	--includedir=${PREFIX:Q}/include/libsidplay2

.include "../../mk/bsd.pkg.mk"
