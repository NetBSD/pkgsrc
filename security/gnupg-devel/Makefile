# $NetBSD: Makefile,v 1.2 2004/10/24 09:03:17 shannonjr Exp $
#

DISTNAME=		gnupg-1.9.11
PKGNAME=		gnupg-devel-1.9.11
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
COMMENT=		Utility programs that come with GnuPG 1.9 (experimental branch)

BUILD_USES_MSGFMT=      yes

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=         yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
GNU_CONFIGURE=          yes
USE_GNU_TOOLS+=         make
CRYPTO=                 yes
CONFIGURE_ARGS+=        --with-static-rnd=auto
CONFIGURE_ARGS+=        --without-included-gettext
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

TEST_TARGET=            check

# We need gettext-lib >= 0.14.1 for NLS support
.include "../../devel/gettext-lib/buildlink3.mk"
GETTEXT_IS_TOO_OLD!=if ${PKG_ADMIN} pmatch 'gettext-lib < 0.14.1' gettext-lib ; then \
		${ECHO} "yes";	\
	else 	\
		${ECHO} "no";	\
	fi
.if GETTEXT_IS_TOO_OLD
CONFIGURE_ARGS+=	--disable-nls
.endif

## If no options are specified, only gpg-agent is built. This
## is sufficient for OpenPGP/MIME support in Kmail
## SMIME support is provided by gpgsm. This support is 
## in the alpha stage of development. 
PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg2
PKG_SUPPORTED_OPTIONS=	gpgsm
.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Mgpgsm)
CONFIGURE_ARGS+=	--enable-agent-only
.else
.include "../../security/dirmngr/buildlink3.mk"
.endif

# This package will only build with pth
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

post-install:
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
.if !GETTEXT_IS_TOO_OLD
	${ECHO} '${PKGLOCALEDIR}/locale/de/LC_MESSAGES/gnupg2.mo >>${PLIST_SRC}
.endif
.if !empty(PKG_OPTIONS:Mgpgsm)
	${CAT} -f ${PKGDIR}/PLIST.gpgsm >> ${PLIST_SRC}
.endif

BUILDLINK_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
