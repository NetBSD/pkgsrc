# $NetBSD: Makefile,v 1.15 2012/09/15 10:05:12 obache Exp $
#

DISTNAME=	ibus-pinyin-1.4.0
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

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "Linux"
.  include "../../devel/libuuid/buildlink3.mk"
.endif

.if (!empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)) || !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--disable-boost
.else
CONFIGURE_ARGS+=	--enable-boost
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}
.include "../../devel/boost-headers/buildlink3.mk"
SUBST_CLASSES+=		shared_ptr
SUBST_STAGE.shared_ptr=	post-configure
SUBST_FILES.shared_ptr=	src/*.h
SUBST_SED.shared_ptr=	-e 's,std::shared_ptr,boost::shared_ptr,g'
.endif

.include "../../inputmethod/ibus/bad-env-usage.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
