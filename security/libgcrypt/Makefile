# $NetBSD: Makefile,v 1.5 2003/07/17 22:52:57 grant Exp $
#

DISTNAME=	libgcrypt-1.1.12
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

TEXINFO_OVERRIDE=	YES
TEXINFO_REQD=		4.0

.include "../../mk/bsd.prefs.mk"

# Our "libtool" doesn't like the crafted ".lo" files with the assembly
# implementations. So we use the bundled "libtool" for NetBSD-i386 ELF
# and ours otherwise.
.if ${MACHINE_GNU_PLATFORM} != i386--netbsdelf && ${MACHINE_GNU_PLATFORM} != alpha--netbsd
CONFIGURE_ARGS+=	--disable-asm
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
