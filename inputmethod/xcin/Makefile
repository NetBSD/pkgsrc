# $NetBSD: Makefile,v 1.11 2004/02/14 17:21:43 jlam Exp $
#

DISTNAME=	xcin-2.5.3.pre2
PKGNAME=	xcin-2.5.3rc2
PKGREVISION=	2
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/devel/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xcin.linux.org.tw/
COMMENT=	Chinese XIM server

WRKSRC=			${WRKDIR}/xcin
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db3}/lib
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db3}/include/db3

post-extract:
	${MV} ${WRKSRC}/doc/man ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xcin
	cd ${WRKSRC}/doc && ${PAX} -rw * ${PREFIX}/share/doc/xcin

.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/db3/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../inputmethod/libtabe/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
