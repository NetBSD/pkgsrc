# $NetBSD: Makefile,v 1.21 2013/02/01 22:21:10 wiz Exp $
#

DISTNAME=		libassuan-1.0.5
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/libassuan/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/libassuan/
COMMENT=		The IPC library used by some GnuPG related software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_TOOLS+=		autoconf autoreconf automake
USE_LIBTOOL=		yes
###
### XXX By default, this package will build with -fPIC on linux.
###	Instead, let's patch it to use libtool and use --with-pic
###	to build position-independent code when possible.
CONFIGURE_ARGS+=	--with-pic
TEST_TARGET=		check

LIBS.SunOS+=		-lrt

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

pre-configure:
	cd ${WRKSRC} && libtoolize
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} autogen.sh

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
