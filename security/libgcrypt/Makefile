# $NetBSD: Makefile,v 1.2 2003/02/02 22:00:24 tron Exp $

DISTNAME=	libgcrypt-1.1.11
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/alpha/libgcrypt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnu.org/directory/security/libgcrypt.html
COMMENT=	GNU's cryptographic library

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

TEXINFO_OVERRIDE=	YES
TEXINFO_REQD=		4.0

.include "../../mk/bsd.prefs.mk"

# Our "libtool" doesn't like the crafted ".lo" files with the assembly
# implementations. So we use the bundled "libtool" for NetBSD-i386 ELF
# and ours otherwise.
.if ${MACHINE_GNU_PLATFORM} != i386--netbsdelf
CONFIGURE_ARGS+=	--disable-asm
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
