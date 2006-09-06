# $NetBSD: Makefile,v 1.33 2006/09/06 11:41:41 markd Exp $

DISTNAME=	libgcrypt-1.2.3
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/libgcrypt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/security/libgcrypt.html
COMMENT=	GNU cryptographic library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

TEXINFO_REQD=		4.0
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-alpha) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-sparc)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
