# $NetBSD: Makefile,v 1.3 2014/08/17 10:45:05 wiz Exp $

DISTNAME=	notmuch-0.18.1
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notmuchmail.org/
COMMENT=	Mail indexer
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS+=	PYTHONBIN=${PYTHONBIN}

.include "options.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # as of 0.18
.include "../../lang/python/application.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.5.2
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
