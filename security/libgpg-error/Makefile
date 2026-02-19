# $NetBSD: Makefile,v 1.101 2026/02/19 07:35:27 wiz Exp $

DISTNAME=	libgpg-error-1.59
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=libgpg-error/}
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

PKGCONFIG_OVERRIDE+=		src/gpg-error.pc
# compared to 'known good' values with rpath during build
PKGCONFIG_OVERRIDE_STAGE=	post-build

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
