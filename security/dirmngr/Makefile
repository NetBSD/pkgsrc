# $NetBSD: Makefile,v 1.3 2004/11/05 22:12:17 jmmv Exp $
#

DISTNAME=		dirmngr-0.5.6
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/dirmngr/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/aegypten2
COMMENT=		X509 certificate and CRL downloader

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		awk
USE_PKGLOCALEDIR=	yes

CONFIGURE_ENV+=		BUILDLINK_PREFIX_openldap=${BUILDLINK_PREFIX.openldap}

INFO_FILES=		dirmngr.info

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
