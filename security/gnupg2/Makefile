# $NetBSD: Makefile,v 1.65 2016/03/20 22:03:17 wiz Exp $

DISTNAME=	gnupg-2.0.29
PKGNAME=	${DISTNAME:S/gnupg/gnupg2/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	GnuPG with OpenPGP and S/MIME capabilities
LICENSE=	gnu-gpl-v3

INFO_FILES=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-pinentry-pgm=${PREFIX}/bin/pinentry

.include "../../mk/bsd.prefs.mk"

# Sometimes wrong include file gets detected, e.g. for Clang
.if defined(OSX_SDK_PATH) && exists(${OSX_SDK_PATH:Q}/usr/include/stdint.h)
CONFIGURE_ENV+=		gl_cv_absolute_stdint_h=${OSX_SDK_PATH:Q}/usr/include/stdint.h
.elif exists(/usr/include/stdint.h)
CONFIGURE_ENV+=		gl_cv_absolute_stdint_h=/usr/include/stdint.h
.endif

TEST_TARGET=		check

DEPENDS+=	pinentry-[0-9]*:../../security/pinentry

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pth/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.5.0
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.4
.include "../../security/libgpg-error/buildlink3.mk"
BUILDLINK_API_DEPENDS.libksba+=		libksba>=1.0.2
.include "../../security/libksba/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
