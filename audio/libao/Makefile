# $NetBSD: Makefile,v 1.4 2001/03/28 10:21:55 wiz Exp $

DISTNAME=	libao-0.6.0
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

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
