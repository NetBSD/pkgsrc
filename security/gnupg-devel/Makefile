# $NetBSD: Makefile,v 1.18.2.1 2006/12/06 18:35:02 ghen Exp $
#

DISTNAME=		gnupg-1.9.22
PKGNAME=		${DISTNAME:S/gnupg/gnupg-devel/}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		pth-2.0.4.tar.gz
SITES.pth-2.0.4.tar.gz=	${MASTER_SITE_GNU:=pth/}

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
COMMENT=		Utility programs that come with GnuPG 1.9 (experimental branch)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-static-rnd=auto
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-pth-prefix=${WRKDIR}/pth
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
pre-configure:
	cd  ${WRKDIR}/pth-2.0.4 && ./configure --prefix=${WRKDIR}/pth --enable-pthread --enable-static --disable-shared && ${MAKE} install

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
