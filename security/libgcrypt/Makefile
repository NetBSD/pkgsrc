# $NetBSD: Makefile,v 1.12 2004/02/10 00:13:24 jlam Exp $
#

DISTNAME=	libgcrypt-1.1.90
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/alpha/libgcrypt/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/security/libgcrypt.html
COMMENT=	GNU cryptographic library

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=		4.0
INFO_FILES=		gcrypt.info

.include "../../mk/bsd.prefs.mk"

# Our "libtool" doesn't like the crafted ".lo" files with the assembly
# implementations. So we use the bundled "libtool" for NetBSD-i386 ELF
# and ours otherwise.
#
.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
CONFIGURE_ARGS+=	--disable-asm
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
.endif

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "native")
CONFIGURE_ARGS+=	--without-pth
.endif

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
