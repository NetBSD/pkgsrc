# $NetBSD: Makefile,v 1.7 2001/12/30 08:00:45 lukem Exp $

DISTNAME=	libogg-1.0rc2
PKGNAME=	libogg-1.0.0.6
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLIST_SUBST+=		DISTNAME=${DISTNAME}

GCC_VERSION!=gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
IGNORE=		"gcc ${GCC_VERSION} cannot be used, as it generates bad ogg files"
.endif

.include "../../mk/bsd.pkg.mk"
