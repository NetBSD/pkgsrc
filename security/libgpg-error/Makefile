# $NetBSD: Makefile,v 1.11 2005/05/15 22:22:48 jschauma Exp $
#

DISTNAME=	libgpg-error-1.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgpg-error/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

# XXX See HACKS
.if ${OPSYS} != IRIX
USE_GNU_TOOLS+=		awk
.endif

MAKE_ENV+=		LC_ALL="C"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
