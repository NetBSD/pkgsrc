# $NetBSD: Makefile,v 1.14 2002/01/02 12:39:36 lukem Exp $

DISTNAME=	libvorbis-1.0rc3
PKGNAME=	libvorbis-1.0.0.7
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_DIR}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLIST_SUBST+=		DISTNAME=${DISTNAME}

GCC_VERSION!=gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
IGNORE=		"gcc ${GCC_VERSION} cannot be used, as it generates bad ogg files"
.endif

.include "../../audio/libogg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
