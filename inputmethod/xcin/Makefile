# $NetBSD: Makefile,v 1.24 2008/05/26 02:13:20 joerg Exp $
#

DISTNAME=	xcin-2.5.3.pre2
PKGNAME=	xcin-2.5.3rc2
PKGREVISION=	6
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/devel/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xcin.linux.org.tw/
COMMENT=	Chinese XIM server

WRKSRC=			${WRKDIR}/xcin
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pax perl:run

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db3}/lib
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db3}/include/db3

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	share/doc/xcin

EGDIR=			${PREFIX}/share/examples/xcin
CONF_FILES=		${EGDIR}/xcinrc ${PKG_SYSCONFDIR}/xcinrc

.if ${OPSYS} == "NetBSD"
EUC_LOCALE=	euccn
.else
EUC_LOCALE=	euc
.endif

PLIST_SUBST+=	EUC_LOCALE=${EUC_LOCALE}

post-extract:
	${CP} ${FILESDIR}/xcinrc.DRAGONFLY ${WRKSRC}/etc

post-install:
	cd ${WRKSRC}/doc && pax -rw	\
		-s ',^\./man$$,,' -s ',^\./man/.*,,'	\
		. ${PREFIX}/share/doc/xcin

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/db3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../inputmethod/libtabe/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
