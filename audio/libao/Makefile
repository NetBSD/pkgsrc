# $NetBSD: Makefile,v 1.5 2001/08/08 09:18:28 lukem Exp $

DISTNAME=	libao-0.7.0
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/rc1/unix/

MAINTAINER=	reed@reedmedia.net
COMMENT=	cross-platform audio library

BUILD_DEPENDS+=	automake-1.4:../../devel/automake
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

PLIST_SUBST+=	VERSION="${DISTNAME}"
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
