# $NetBSD: Makefile,v 1.17.2.2 2002/06/21 23:04:59 jlam Exp $

DISTNAME=	libvorbis-1.0rc3
PKGNAME=	libvorbis-1.0.0.7
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

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
