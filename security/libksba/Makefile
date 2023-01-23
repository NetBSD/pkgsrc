# $NetBSD: Makefile,v 1.38.2.1 2023/01/23 17:38:29 spz Exp $

DISTNAME=	libksba-1.6.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libksba/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/related_software/libksba/index.html
COMMENT=	X.509 library
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	src/ksba.pc.in
INFO_FILES=		yes
TEST_TARGET=		check
TEXINFO_REQD=		4.0

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == yes
CONFIGURE_ARGS+=	CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.2
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
