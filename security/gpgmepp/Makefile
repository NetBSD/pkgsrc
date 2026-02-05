# $NetBSD: Makefile,v 1.52 2026/02/05 12:05:34 mef Exp $

DISTNAME=	gpgmepp-2.0.0
CATEGORIES=	security
MASTER_SITES=	https://www.gnupg.org/ftp/gcrypt/gpgmepp/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/software/gpgme/index.html
COMMENT=	C++ library for OpenPGP using GnuPG
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
# gcc-7.5 of NetBSD 9.4 is missing this feature
USE_CXX_FEATURES+=	charconv

PKGCONFIG_OVERRIDE+=	src/gpgmepp.pc.in

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.47
.include "../../security/libgpg-error/buildlink3.mk"
BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=2.0.0
.include "../../security/gpgme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
