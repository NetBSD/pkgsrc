# $NetBSD: Makefile,v 1.19 2008/04/25 15:16:31 smb Exp $
#

DISTNAME=		pinentry-0.7.2
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}

INFO_FILES=		yes

.include "options.mk"

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
