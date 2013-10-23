# $NetBSD: Makefile,v 1.22 2013/10/23 12:39:55 obache Exp $
#

DISTNAME=	ibus-pinyin-1.5.0
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Chinese Pinyin and Bopomofo engines for IBus input platform
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config gmake intltool msgfmt

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-pinyin.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

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

.include "../../converters/pyzy/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
