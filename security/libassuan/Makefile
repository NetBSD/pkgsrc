# $NetBSD: Makefile,v 1.16 2008/09/07 02:40:53 bjs Exp $
#

DISTNAME=		libassuan-1.0.5
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/libassuan/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/libassuan/
COMMENT=		The IPC library used by some GnuPG related software

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

pre-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} autogen.sh && \
		${TOUCH} ${TOUCH_FLAGS} libtool

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
