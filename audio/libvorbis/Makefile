# $NetBSD: Makefile,v 1.24 2003/09/12 17:55:53 recht Exp $

DISTNAME=	libvorbis-1.0
PKGNAME=	libvorbis-1.0.0.8
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/compiler.mk"
.include "../../mk/bsd.pkg.mk"
