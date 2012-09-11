# $NetBSD: Makefile,v 1.78 2012/09/11 23:19:35 asau Exp $
#
# NOTE: If you update this package, it is *mandatory* that you update
# 	pkgsrc/pkgtools/libnbcompat/files/README to reflect the actual
#	list of tested and supported platforms.
#

DISTNAME=		libnbcompat-20120702
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Portable NetBSD compatibility library

GNU_CONFIGURE=		yes
MAKE_ENV+=		LIBMODE=${LIBMODE}

# Enable by default for standalone builds
CONFIGURE_ARGS+=	--enable-db

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
