# $NetBSD: Makefile,v 1.8 2015/12/05 21:26:00 adam Exp $

DISTNAME=	virtinst-0.600.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://virt-manager.org/download/sources/virtinst/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://virt-manager.org/
COMMENT=	Module to help in starting installations inside of virtual machines
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	msgfmt xgettext

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.600.3

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man pages installation path
SUBST_FILES.man=	setup.py
SUBST_SED.man=		-e 's,@@PKGMANDIR@@,${PKGMANDIR},'

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
