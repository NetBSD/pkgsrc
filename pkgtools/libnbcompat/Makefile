# $NetBSD: Makefile,v 1.91 2023/09/04 19:51:19 jperkin Exp $
#
# NOTE: If you update this package, it is *mandatory* that you update
# 	pkgsrc/pkgtools/libnbcompat/files/README to reflect the actual
#	list of tested and supported platforms.
#

PKGNAME=		libnbcompat-20230904
CATEGORIES=		pkgtools devel

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Portable NetBSD compatibility library

GNU_CONFIGURE=		yes
MAKE_ENV+=		LIBMODE=${LIBMODE}

# Enable by default for standalone builds
CONFIGURE_ARGS+=	--enable-db

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
