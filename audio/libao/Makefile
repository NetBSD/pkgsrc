# $NetBSD: Makefile,v 1.10 2001/08/29 12:22:38 skrll Exp $

DISTNAME=	libao-0.8.0
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

MAINTAINER=	lukem@netbsd.org
COMMENT=	cross-platform audio library

BUILD_DEPENDS+=	automake>=1.4:../../devel/automake

PLIST_SUBST+=	VERSION="${DISTNAME}"
USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		ac_cv_path_ESD_CONFIG=no

.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
