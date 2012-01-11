# $NetBSD: Makefile,v 1.15 2012/01/11 19:43:23 hans Exp $

DISTNAME=		mpc-0.20
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Command-line client for musicpd
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

LIBS.SunOS+=		${BUILDLINK_LDADD.iconv}

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
