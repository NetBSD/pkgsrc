# $NetBSD: Makefile,v 1.19 2022/06/30 11:18:52 nia Exp $

DISTNAME=	virtinst-0.600.3
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://virt-manager.org/download/sources/virtinst/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://virt-manager.org/
COMMENT=	Module to help in starting installations inside of virtual machines
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	msgfmt xgettext

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.600.3

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man pages installation path
SUBST_FILES.man=	setup.py
SUBST_SED.man=		-e 's,@@PKGMANDIR@@,${PKGMANDIR},'

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
