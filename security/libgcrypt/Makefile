# $NetBSD: Makefile,v 1.74 2016/02/11 13:36:37 wiz Exp $

DISTNAME=	libgcrypt-1.6.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgcrypt/ \
		http://gd.tuwien.ac.at/privacy/gnupg/libgcrypt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libgcrypt/
COMMENT=	GNU cryptographic library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

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

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.11
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
