# $NetBSD: Makefile,v 1.10.2.2 2002/06/21 23:04:59 jlam Exp $

DISTNAME=	libogg-1.0rc3
PKGNAME=	libogg-1.0.0.7
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		DISTNAME=${DISTNAME}

GCC_VERSION!=		gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as it generates bad ogg files.
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../mk/bsd.pkg.mk"
