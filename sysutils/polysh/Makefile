# $NetBSD: Makefile,v 1.1 2012/11/25 11:14:14 imil Exp $
#

DISTNAME=	polysh-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://guichaz.free.fr/polysh/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/polysh/
COMMENT=	Aggregate several remote shells into one
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup+=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
