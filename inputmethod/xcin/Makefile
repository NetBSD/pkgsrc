# $NetBSD: Makefile,v 1.18 2006/01/28 03:03:11 rxg Exp $
#

DISTNAME=	xcin-2.5.3.pre2
PKGNAME=	xcin-2.5.3rc2
PKGREVISION=	5
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/devel/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xcin.linux.org.tw/
COMMENT=	Chinese XIM server

WRKSRC=			${WRKDIR}/xcin
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db3}/lib
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db3}/include/db3

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	share/doc/xcin

EGDIR=			${PREFIX}/share/examples/xcin
CONF_FILES=		${EGDIR}/xcinrc ${PKG_SYSCONFDIR}/xcinrc

post-install:
	cd ${WRKSRC}/doc && ${PAX} -rw	\
		-s ',^\./man$$,,' -s ',^\./man/.*,,'	\
		. ${PREFIX}/share/doc/xcin

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/db3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../inputmethod/libtabe/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
