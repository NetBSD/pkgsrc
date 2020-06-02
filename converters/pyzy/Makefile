# $NetBSD: Makefile,v 1.24 2020/06/02 08:22:33 adam Exp $

DISTNAME=	pyzy-0.1.0
PKGREVISION=	16
CATEGORIES=	converters chinese
MASTER_SITES=	http://pyzy.googlecode.com/files/
DISTFILES=	${DEFAULT_DISTFILES} ${DBTAR}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyzy/pyzy
COMMENT=	Chinese PinYin and Bopomofo conversion library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pyzy-1.0.pc.in

CONFIGURE_ARGS+=	--disable-db-android
CONFIGURE_ARGS+=	--enable-db-open-phrase

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# Reduce noise to a level that real warnings can be seen
CXXFLAGS+=	-Wno-gnu-designator
.endif

# taken from ${WRKSRC}/data/db/open-phrase/Makefile.am
DBVER=		1.0.0
DBTAR=		pyzy-database-${DBVER}.tar.bz2

post-extract:
	${RUN} cd ${WRKSRC}/data/db/open-phrase;	\
	mkdir -p db;					\
	mv ${WRKDIR}/db/main.db db/open-phrase.db;	\
	touch ${DBTAR} stamp-db

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.  include "../../devel/libuuid/buildlink3.mk"
.endif

.if (!empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)) || !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--disable-boost
.else
CONFIGURE_ARGS+=	--enable-boost
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}
.include "../../devel/boost-headers/buildlink3.mk"
.endif

# https://github.com/pyzy/pyzyissues/detail?id=4
.include "../../inputmethod/ibus/bad-env-usage.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.24.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
