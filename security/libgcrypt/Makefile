# $NetBSD: Makefile,v 1.106 2022/03/29 07:16:00 adam Exp $

DISTNAME=	libgcrypt-1.10.1
CATEGORIES=	security
MASTER_SITES=	https://gnupg.org/ftp/gcrypt/libgcrypt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnupg.org/software/libgcrypt/
COMMENT=	GNU cryptographic library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
TEXINFO_REQD=		4.0
INFO_FILES=		yes

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-fheinous-gnu-extensions
.endif

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	src/libgcrypt-config.in
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Fixing rpath flags
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

.include "options.mk"

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.13
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
