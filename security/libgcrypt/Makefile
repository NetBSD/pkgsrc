# $NetBSD: Makefile,v 1.62 2014/07/18 10:36:28 ryoon Exp $

DISTNAME=	libgcrypt-1.6.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/libgcrypt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/project/libgcrypt/
COMMENT=	GNU cryptographic library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
CONFIGURE_ARGS+=	--disable-aesni-support

# SCO OpenServer 5.0.7/3.2 has no socklen_t, but it is defined in pthread.h
# from builtin GNU pth.
.if ${OS_VARIANT} == "SCOOSR5"
CONFIGURE_ENV+=		ac_cv_type_socklen_t=yes
CONFIGURE_ENV+=		gl_cv_socklen_t_equiv=int
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-fheinous-gnu-extensions
.endif

.include "options.mk"

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
