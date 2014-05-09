# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:19 wiz Exp $

DISTNAME=	polysh-0.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://guichaz.free.fr/polysh/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/polysh/
COMMENT=	Aggregate several remote shells into one
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.4
REPLACE_PYTHON=	polysh/rb_tree.py

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup+=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
