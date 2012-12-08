# $NetBSD: Makefile,v 1.1 2012/12/08 22:43:10 adam Exp $

DISTNAME=	openjpeg-1.5.1
PKGNAME=	${DISTNAME:S/openjpeg/openjpeg15/}
CATEGORIES=	graphics
MASTER_SITES=	http://openjpeg.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openjpeg.org/
COMMENT=	JPEG 2000 library
LICENSE=	2-clause-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--disable-doc
GNU_CONFIGURE=		yes

CFLAGS+=	-DHAVE_POSIX_MEMALIGN

.include "../../mk/bsd.pkg.mk"
