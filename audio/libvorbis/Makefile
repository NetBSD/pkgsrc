# $NetBSD: Makefile,v 1.11 2001/11/29 19:46:10 jlam Exp $

DISTNAME=	libvorbis-1.0rc2
PKGNAME=	libvorbis-1.0.0.6
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

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

.include "../../audio/libogg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
