# $NetBSD: Makefile,v 1.46 2009/12/18 18:54:24 drochner Exp $

DISTNAME=	libgcrypt-1.4.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/libgcrypt/
EXTRACT_SUFX=	.tar.bz2
# don't remove this -- see options.mk
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/security/libgcrypt.html
COMMENT=	GNU cryptographic library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

TEXINFO_REQD=		4.0
INFO_FILES=		yes # PLIST

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
