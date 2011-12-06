# $NetBSD: Makefile,v 1.9 2011/12/06 19:53:27 joerg Exp $
#

DISTNAME=	ibus-pinyin-1.3.11
PKGREVISION=	2
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/
DISTFILES=	${DEFAULT_DISTFILES} ${DBTAR}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Chinese Pinyin and Bopomofo engines for IBus input platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config gmake intltool msgfmt

# taken from ${WRKSRC}/data/db/open-phrase/Makefile.in
DBVER=		1.2.99
DBTAR=		pinyin-database-${DBVER}.tar.bz2

post-extract:
	${RUN} cd ${WRKSRC}/data/db/open-phrase;	\
	mkdir -p db;					\
	mv ${WRKDIR}/db/main.db db/open-phrase.db;	\
	touch ${DBTAR} stamp-db

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-pinyin.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--disable-db-android
CONFIGURE_ARGS+=	--enable-db-open-phrase
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "Linux"
.  include "../../devel/libuuid/buildlink3.mk"
.endif

.if (!empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)) || !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=		-std=c++0x
.endif

.include "../../inputmethod/ibus/bad-env-usage.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
