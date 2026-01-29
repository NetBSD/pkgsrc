# $NetBSD: Makefile,v 1.51 2026/01/29 13:49:39 wiz Exp $

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

PKGCONFIG_OVERRIDE+=	src/gpgmepp.pc.in

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.47
.include "../../security/libgpg-error/buildlink3.mk"
BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=2.0.0
.include "../../security/gpgme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
