# $NetBSD: Makefile,v 1.9 2015/02/26 12:17:04 wiz Exp $

DISTNAME=	notmuch-0.19
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notmuchmail.org/
COMMENT=	Mail indexer
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS+=	PYTHONBIN=${PYTHONBIN}

.include "options.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		gnuld
SUBST_STAGE.gnuld=	pre-configure
SUBST_FILES.gnuld=	lib/Makefile.local
SUBST_SED.gnuld=	-e 's/-Wl,--[^ ]*//g'
.endif

SUBST_CLASSES+=		docutils
SUBST_SED.docutils+=	-e "s,rst2man.py,rst2man-${PYVERSSUFFIX}.py,"
SUBST_FILES.docutils+=	configure doc/prerst2man.py
SUBST_STAGE.docutils=	pre-configure
SUBST_MESSAGE.docutils=	Fix docutils command names.

LDFLAGS.SunOS+=	-lnsl

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # as of 0.19
.include "../../lang/python/application.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
