# $NetBSD: Makefile,v 1.19 2002/08/25 18:38:16 jlam Exp $

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

GCC_VERSION!=gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as it generates bad ogg files.
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
