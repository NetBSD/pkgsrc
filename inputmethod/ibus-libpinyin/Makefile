# $NetBSD: Makefile,v 1.29 2022/06/30 11:18:30 nia Exp $

DISTNAME=	ibus-libpinyin-1.12.0
PKGREVISION=	4
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpinyin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libpinyin/ibus-libpinyin/
COMMENT=	Intelligent Pinyin engine based on libpinyin for IBus
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYVERSION_DIGIT=		${PYPKGPREFIX:S/py//}
PLIST_SUBST+=			PYVERSION_DIGIT=${PYVERSION_DIGIT}

.include "options.mk"

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

.include "../../devel/glib2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../textproc/libpinyin/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
