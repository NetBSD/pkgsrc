# $NetBSD: Makefile,v 1.6 2001/08/14 14:33:29 lukem Exp $

DISTNAME=	libao-0.8.0
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

MAINTAINER=	lukem@netbsd.org
COMMENT=	cross-platform audio library

BUILD_DEPENDS+=	automake-1.4:../../devel/automake
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

PLIST_SUBST+=	VERSION="${DISTNAME}"
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
