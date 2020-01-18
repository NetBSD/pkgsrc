# $NetBSD: Makefile,v 1.86 2020/01/18 23:33:25 rillig Exp $
#
# NOTE: If you update this package, it is *mandatory* that you update
# 	pkgsrc/pkgtools/libnbcompat/files/README to reflect the actual
#	list of tested and supported platforms.
#

PKGNAME=		libnbcompat-20190708
CATEGORIES=		pkgtools devel

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Portable NetBSD compatibility library

GNU_CONFIGURE=		yes
MAKE_ENV+=		LIBMODE=${LIBMODE}

# Enable by default for standalone builds
CONFIGURE_ARGS+=	--enable-db

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
