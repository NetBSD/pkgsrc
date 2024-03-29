# $NetBSD: Makefile,v 1.88 2024/02/25 15:05:34 wiz Exp $

DISTNAME=	libgpg-error-1.48
CATEGORIES=	security
MASTER_SITES=	https://www.gnupg.org/ftp/gcrypt/libgpg-error/
MASTER_SITES+=	ftp://ftp.gnupg.org/gcrypt/libgpg-error/
MASTER_SITES+=	ftp://ftp.ring.gr.jp/pub/net/gnupg/libgpg-error/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/software/libgpg-error/index.html
COMMENT=	Definitions of common error values for all GnuPG components
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-install-gpg-error-config
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == yes
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.else
CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}\ ${CFLAGS:M*:Q}
.endif

.if ${MACHINE_PLATFORM:MDarwin-8.*-powerpc}
CFLAGS+=	-D__DARWIN_UNIX03
.endif

.if ${MACHINE_PLATFORM:MSunOS-5.10-*}
LIBS+=	-lrt
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
