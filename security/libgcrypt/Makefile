# $NetBSD: Makefile,v 1.41 2008/04/29 11:03:50 wiz Exp $

DISTNAME=	libgcrypt-1.4.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/libgcrypt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/security/libgcrypt.html
COMMENT=	GNU cryptographic library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

TEXINFO_REQD=		4.0
INFO_FILES=		yes # PLIST

#LICENSE=		gnu-gpl-v2 gnu-lgpl-v21

.include "../../mk/bsd.prefs.mk"

.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-alpha) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-sparc) && \
    empty(MACHINE_PLATFORM:M*-*-hppa)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "options.mk"

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
