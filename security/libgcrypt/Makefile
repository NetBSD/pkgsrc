# $NetBSD: Makefile,v 1.9 2003/12/06 00:26:59 xtraeme Exp $
#

DISTNAME=	libgcrypt-1.1.90
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/alpha/libgcrypt/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/security/libgcrypt.html
COMMENT=	GNU cryptographic library

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=		4.0
INFO_FILES=		gcrypt.info

.include "../../mk/bsd.prefs.mk"

# Our "libtool" doesn't like the crafted ".lo" files with the assembly
# implementations. So we use the bundled "libtool" for NetBSD-i386 ELF
# and ours otherwise.
.if ${MACHINE_GNU_PLATFORM} != i386--netbsdelf && ${MACHINE_GNU_PLATFORM} != alpha--netbsd
CONFIGURE_ARGS+=	--disable-asm
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
.endif

.if exists(/usr/include/pthread.h)
CONFIGURE_ARGS+=	--without-pth
.endif

.include "../../mk/pthread.buildlink2.mk"
.include "../../security/libgpg-error/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
