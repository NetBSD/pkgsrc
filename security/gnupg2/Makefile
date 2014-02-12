# $NetBSD: Makefile,v 1.51 2014/02/12 23:18:32 tron Exp $

DISTNAME=	gnupg-2.0.22
PKGNAME=	${DISTNAME:S/gnupg/gnupg2/}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	GNUpg with OpenPGP and S/MIME capabilities
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INFO_FILES=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-pinentry-pgm=${BUILDLINK_PREFIX.pinentry}/bin/pinentry

# Sometimes wrong include file gets detected, e.g. for Clang
.if exists(/usr/include/stdint.h)
CONFIGURE_ENV+=		gl_cv_absolute_stdint_h=/usr/include/stdint.h
.endif

TEST_TARGET=		check

.include "options.mk"

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.4
BUILDLINK_API_DEPENDS.libksba+=		libksba>=1.0.2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pth/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
