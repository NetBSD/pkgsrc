# $NetBSD: Makefile,v 1.20 2002/10/02 08:41:23 jlam Exp $

DISTNAME=	libvorbis-1.0
PKGNAME=	libvorbis-1.0.0.8
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

#BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.include "../../audio/libogg/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
