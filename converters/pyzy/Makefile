# $NetBSD: Makefile,v 1.1 2013/10/23 11:41:25 obache Exp $

DISTNAME=	pyzy-0.1.0
CATEGORIES=	converters chinese
MASTER_SITES=	http://pyzy.googlecode.com/files/
DISTFILES=	${DEFAULT_DISTFILES} ${DBTAR}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pyzy/
COMMENT=	Chinese PinYin and Bopomofo conversion library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pyzy-1.0.pc.in

CONFIGURE_ARGS+=	--disable-db-android
CONFIGURE_ARGS+=	--enable-db-open-phrase

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
SUBST_CLASSES+=		shared_ptr
SUBST_STAGE.shared_ptr=	post-configure
SUBST_FILES.shared_ptr=	src/*.h
SUBST_SED.shared_ptr=	-e 's,std::shared_ptr,boost::shared_ptr,g'
.endif

.include "../../inputmethod/ibus/bad-env-usage.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.24.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
