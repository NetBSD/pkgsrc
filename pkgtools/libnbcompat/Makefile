# $NetBSD: Makefile,v 1.73 2009/06/10 11:03:47 joerg Exp $
#
# NOTE: If you update this package, it is *mandatory* that you update
# 	pkgsrc/pkgtools/libnbcompat/files/README to reflect the actual
#	list of tested and supported platforms.
#

DISTNAME=		libnbcompat-20090610
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Portable NetBSD compatibility library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
MAKE_ENV+=		LIBMODE=${LIBMODE}

# Enable by default for standalone builds
CONFIGURE_ARGS+=	--enable-db

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
