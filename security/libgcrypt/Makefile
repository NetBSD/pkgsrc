# $NetBSD: Makefile,v 1.19 2004/05/26 05:42:28 tron Exp $

DISTNAME=	libgcrypt-1.2.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/libgcrypt/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/security/libgcrypt.html
COMMENT=	GNU cryptographic library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

TEST_TARGET=	check

TEXINFO_REQD=		4.0
INFO_FILES=		gcrypt.info

.include "../../mk/bsd.prefs.mk"

.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
