# $NetBSD: Makefile,v 1.16 2003/07/17 21:22:42 grant Exp $

DISTNAME=	libogg-1.0
PKGNAME=	libogg-1.0.0.8
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.include "../../mk/gcc.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
