# $NetBSD: Makefile,v 1.2 2002/07/16 15:40:59 agc Exp $
#

DISTNAME=	xcin-2.5.3.pre2
PKGNAME=	xcin-2.5.3rc2
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/devel/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://xcin.linux.org.tw/
COMMENT=	Chinese XIM server

USE_PERL5=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/script/ltmain.sh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_DIR}/include/db3

USE_BUILDLINK_ONLY=	yes

WRKSRC=		${WRKDIR}/xcin

post-extract:
	${MV} ${WRKSRC}/doc/man ${WRKSRC}

post-configure:
	# this pkg generates libtool script from configure file
	cd ${WRKSRC} && script/ltmain.sh

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xcin
	cd ${WRKSRC}/doc; ${PAX} -rw * ${PREFIX}/share/doc/xcin

.include "../../converters/libiconv/buildlink.mk"
.include "../../databases/db3/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../inputmethod/libtabe/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
