# $NetBSD: Makefile,v 1.27 2010/06/02 12:36:57 adam Exp $

DISTNAME=	xcin-2.5.3.pre2
PKGNAME=	xcin-2.5.3rc2
PKGREVISION=	8
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/devel/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xcin.linux.org.tw/
COMMENT=	Chinese XIM server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

WRKSRC=			${WRKDIR}/xcin
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pax perl:run
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-db-lib=${BDBBASE}/lib
CONFIGURE_ARGS+=	--with-db-inc=${BDBBASE}/include/${BDB_TYPE}

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
		. ${DESTDIR}${PREFIX}/share/doc/xcin

INSTALL_MAKE_FLAGS+=	program_prefix=${DESTDIR}

BUILDLINK_DEPMETHOD.libXt?=	build

BDB_ACCEPTED=	db2 db3 db4 db5
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libchewing02/buildlink3.mk"
.include "../../inputmethod/libtabe/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
