# $NetBSD: Makefile,v 1.3 2010/02/10 19:17:40 joerg Exp $
#

DISTNAME=	uniconvertor-1.1.4
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://sk1project.org/downloads/uniconvertor/v1.1.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sk1project.org/
COMMENT=	Universal vector graphics translator
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/UniConvertor-1.1.4
PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		pybin
SUBST_STAGE.pybin=	post-build
SUBST_FILES.pybin=	src/uniconvertor
SUBST_VARS.pybin=	PYTHONBIN

# it is renamed because tgif expects it that way, and to avoid
# a conflict with netatalk
post-extract:
	${MV} ${WRKSRC}/src/uniconv ${WRKSRC}/src/uniconvertor

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
