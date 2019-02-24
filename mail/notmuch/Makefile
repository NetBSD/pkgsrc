# $NetBSD: Makefile,v 1.43 2019/02/24 10:42:15 wiz Exp $

DISTNAME=	notmuch-0.28.2
CATEGORIES=	mail
MASTER_SITES=	https://notmuchmail.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://notmuchmail.org/
COMMENT=	Mail indexer
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake makeinfo pkg-config
MAKE_FLAGS+=	PYTHON=${PYTHONBIN}
INFO_FILES=	yes
#TEST_TARGET=	check

.include "options.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--without-ruby

SUBST_CLASSES.SunOS+=	gnuld
SUBST_STAGE.gnuld=	pre-configure
SUBST_FILES.gnuld=	lib/Makefile.local
SUBST_SED.gnuld=	-e 's/-Wl,--[^ ]*//g'

SUBST_CLASSES+=		sphinx
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build${PYVERSSUFFIX},"
SUBST_FILES.sphinx+=	bindings/python/docs/Makefile configure doc/Makefile.local
SUBST_STAGE.sphinx=	pre-configure
SUBST_MESSAGE.sphinx=	Fix sphinx command names.

LDFLAGS.SunOS+=	-lnsl

post-extract:
	${MV} ${WRKSRC}/version ${WRKSRC}/version.txt

.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.gmime3+=	gmime3>=3.0.3
.include "../../mail/gmime3/buildlink3.mk"
BUILDLINK_API_DEPENDS.xapian+=	xapian>=1.4
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.5.2
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
