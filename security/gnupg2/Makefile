# $NetBSD: Makefile,v 1.1.1.1 2006/11/17 12:13:11 shannonjr Exp $
#

DISTNAME=		gnupg-2.0.0
PKGNAME=		${DISTNAME:S/gnupg/gnupg2/}
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		pth-2.0.7.tar.gz
SITES.pth-2.0.7.tar.gz=	${MASTER_SITE_GNU:=pth/}
DISTFILES+=		libassuan-1.0.0.tar.bz2
SITES.libassuan-1.0.0.tar.bz2=	ftp://ftp.gnupg.org/gcrypt/libassuan/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
COMMENT=		GNUpg with OpenPGP and S/MIME capabilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		autoconf
USE_TOOLS+=		automake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-static-rnd=auto
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-pth-prefix=${WRKDIR}/pth
CONFIGURE_ARGS+=	--with-libassuan-prefix=${WRKDIR}/libassuan
CONFIGURE_ARGS+=	--enable-maintainer-mode
CONFIGURE_ENV+=		gnupg_cv_pth_is_sane=yes

TEST_TARGET=		check

# XXX It looks like that gpgsm support could be splitted in its own package,
# according to the configure script.  If that's true, this use of the options
# framework is incorrect and should be fixed.
PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg2
PKG_SUPPORTED_OPTIONS=	gpgsm
.include "../../mk/bsd.options.mk"

## If no options are specified, only gpg-agent is built. This
## is sufficient for OpenPGP/MIME support in Kmail
## SMIME support is provided by gpgsm. This support is
## in the alpha stage of development.
PLIST_SRC=	${.CURDIR}/PLIST
.if empty(PKG_OPTIONS:Mgpgsm)
CONFIGURE_ARGS+=	--enable-agent-only
.else
PLIST_SRC+=	${.CURDIR}/PLIST.gpgsm
.  include "../../security/dirmngr/buildlink3.mk"
.endif

# We are building a static pth library and linking against it
# While this is not very satisfying, gpgme hangs in it's gpgsm tests if we depend on the shared (pkgsrc) pth library
# We are also building libassuan here to get libassuan-pth.
pre-configure:
	cd  ${WRKDIR}/pth-2.0.7 && \
	./configure --prefix=${WRKDIR}/pth --enable-pthread --enable-static --disable-shared && \
	${MAKE} install
	cd  ${WRKDIR}/libassuan-1.0.0 && \
	${SETENV} ${CONFIGURE_ENV} ./autogen.sh && \
	${SETENV} ${CONFIGURE_ENV} ./configure --enable-maintainer-mode --prefix=${WRKDIR}/libassuan --with-pth-prefix=${WRKDIR}/pth && \
	${SETENV} ${PKGSRC_MAKE_ENV} ${MAKE} install
	cd  ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.4
BUILDLINK_API_DEPENDS.libksba+=		libksba>=1.0.0

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
