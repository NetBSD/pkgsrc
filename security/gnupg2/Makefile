# $NetBSD: Makefile,v 1.20 2008/04/28 14:21:27 shannonjr Exp $
#

DISTNAME=		gnupg-2.0.7
PKGREVISION=		3
PKGNAME=		${DISTNAME:S/gnupg/gnupg2/}
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		pth-2.0.7.tar.gz
SITES.pth-2.0.7.tar.gz=	${MASTER_SITE_GNU:=pth/}
DISTFILES+=		libassuan-1.0.3.tar.bz2
SITES.libassuan-1.0.3.tar.bz2=	ftp://ftp.gnupg.org/gcrypt/libassuan/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/
COMMENT=		GNUpg with OpenPGP and S/MIME capabilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# ../licommon/libcommon.a
# reported upstream, should be fixed in 2.0.6
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		autoconf
USE_TOOLS+=		automake
USE_TOOLS+=		gettext
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
#LICENSE=		GPLv3

CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-static-rnd=auto
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-pth-prefix=${WRKDIR}/pth
CONFIGURE_ARGS+=	--with-libassuan-prefix=${WRKDIR}/libassuan
CONFIGURE_ARGS+=	--with-pinentry-pgm=${BUILDLINK_PREFIX.pinentry}/bin/pinentry
CONFIGURE_ARGS+=	--enable-maintainer-mode
CONFIGURE_ENV+=		gnupg_cv_pth_is_sane=yes

TEST_TARGET=		check

.include "options.mk"

# We are building a static pth library and linking against it
# While this is not very satisfying, gpgme hangs in its gpgsm tests
# if we depend on the shared (pkgsrc) pth library
# We are also building libassuan here to get libassuan-pth.
pre-configure:
	cd  ${WRKDIR}/pth-2.0.7 && \
	./configure --prefix=${WRKDIR}/pth --enable-pthread --enable-static --disable-shared && \
	${MAKE} install
	cd  ${WRKDIR}/libassuan-1.0.3 && \
	${SETENV} ${CONFIGURE_ENV} ./autogen.sh && \
	${SETENV} ${CONFIGURE_ENV} ./configure --prefix=${WRKDIR}/libassuan --with-pth-prefix=${WRKDIR}/pth && \
	${SETENV} ${PKGSRC_MAKE_ENV} ${MAKE} install
	cd  ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.4
BUILDLINK_API_DEPENDS.libksba+=		libksba>=1.0.2

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
