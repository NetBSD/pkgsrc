# $NetBSD: Makefile,v 1.19 2006/10/20 15:12:20 shannonjr Exp $
#

DISTNAME=	libgpg-error-1.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgpg-error/ \
		http://ftp.gnupg.org/gcrypt/libgpg-error/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

# XXX See HACKS
.if ${OPSYS} == IRIX || !empty(MACHINE_PLATFORM:MNetBSD-[3-9]*)
USE_TOOLS+=		nawk
.else
USE_TOOLS+=		gawk
.endif

MAKE_ENV+=		LC_ALL="C"

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
