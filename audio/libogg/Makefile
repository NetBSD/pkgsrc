# $NetBSD: Makefile,v 1.21 2003/09/25 13:00:18 grant Exp $

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

GCC_REQD=		2.95.3

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.include "../../mk/bsd.pkg.mk"
