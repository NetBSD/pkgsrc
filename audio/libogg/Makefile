# $NetBSD: Makefile,v 1.19 2003/09/25 01:14:31 christos Exp $

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

.include "../../mk/compiler.mk"
.include "../../mk/bsd.pkg.mk"
