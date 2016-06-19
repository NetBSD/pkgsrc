# $NetBSD: Makefile,v 1.31.6.1 2016/06/19 10:35:08 spz Exp $

DISTNAME=	libksba-1.3.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libksba/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/(fr)/related_software/libksba/index.html
COMMENT=	X.509 library
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check
TEXINFO_REQD=		4.0

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.2
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
