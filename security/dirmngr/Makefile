# $NetBSD: Makefile,v 1.2 2004/11/04 20:20:22 shannonjr Exp $
#

DISTNAME=		dirmngr-0.5.6
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/dirmngr/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/aegypten2
COMMENT=		X509 certificate and CRL downloader

BUILD_USES_MSGFMT=	yes

.include "../../mk/bsd.prefs.mk"

INFO_FILES=		dirmngr.info
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=         make
USE_GNU_TOOLS+=		awk
AUTOCONF_REQD=		2.52
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"

# gettext Version 0.12.1 or newer is required for NLS support
.include "../../devel/gettext-lib/buildlink3.mk"
GETTEXT_IS_TOO_OLD!=if ${PKG_ADMIN} pmatch 'gettext-lib < 0.12.1' gettext-lib ; then \
		${ECHO} "yes";  \
	else    \
		${ECHO} "no";   \
	fi

.if GETTEXT_IS_TOO_OLD
CONFIGURE_ARGS+=	--disable-nls
.endif

pre-configure:
			cd ${WRKSRC} && ${AUTOCONF}

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_DEPENDS.libksb+=	libksba>=0.9.6
.include "../../security/libksba/buildlink3.mk"
BUILDLINK_DEPENDS.libassuan+=	libassuan>=0.6.5
.include "../../security/libassuan/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
