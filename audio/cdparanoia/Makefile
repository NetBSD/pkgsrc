# $NetBSD: Makefile,v 1.10 2003/10/20 12:07:23 grant Exp $
#

DISTNAME=	cdparanoia-III-alpha9.8
PKGNAME=	cdparanoia-3.0.9.8
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/paranoia/download/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xiph.org/paranoia/
COMMENT=	CDDA reading utility with extra data verification features

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* Linux-*-*

USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/cdparanoia

MAKE_ENV+=	GCC=yes

LDFLAGS.FreeBSD+=	-lcam

.include "../../mk/bsd.pkg.mk"
