# $NetBSD: Makefile,v 1.15 2022/01/10 20:23:36 wiz Exp $

DISTNAME=	polysh-0.4
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://guichaz.free.fr/polysh/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/polysh/
COMMENT=	Aggregate several remote shells into one
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 # not yet ported as of 0.4
REPLACE_PYTHON=	polysh/rb_tree.py

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_FILES.setup=	setup.py
SUBST_SED.setup+=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
