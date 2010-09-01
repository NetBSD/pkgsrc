# $NetBSD: Makefile,v 1.31 2010/09/01 16:46:41 drochner Exp $
#

DISTNAME=		gnupg-2.0.16
PKGNAME=		${DISTNAME:S/gnupg/gnupg2/}
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/
COMMENT=		GNUpg with OpenPGP and S/MIME capabilities
LICENSE=		gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		autoconf
USE_TOOLS+=		automake
USE_TOOLS+=		gettext
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-static-rnd=auto
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-pinentry-pgm=${BUILDLINK_PREFIX.pinentry}/bin/pinentry
#CONFIGURE_ARGS+=	--enable-maintainer-mode

TEST_TARGET=		check

.include "options.mk"

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.4
BUILDLINK_API_DEPENDS.libksba+=		libksba>=1.0.2

.include "../../devel/pth/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
