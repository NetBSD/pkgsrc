# $NetBSD: Makefile,v 1.9 2002/01/03 21:59:19 tron Exp $

DISTNAME=	libogg-1.0rc3
PKGNAME=	libogg-1.0.0.7
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLIST_SUBST+=		DISTNAME=${DISTNAME}

GCC_VERSION!=		gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../mk/bsd.pkg.mk"
