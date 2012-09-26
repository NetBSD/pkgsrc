# $NetBSD: Makefile,v 1.4 2012/09/26 19:35:02 gls Exp $
#

DISTNAME=	virtinst-0.600.3
CATEGORIES=	sysutils
MASTER_SITES=	http://virt-manager.org/download/sources/virtinst/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://virt-manager.org/
COMMENT=	Module to help in starting installations inside of virtual machines
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	msgfmt xgettext
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man pages installation path
SUBST_FILES.man=	setup.py
SUBST_SED.man=		-e 's,@@PKGMANDIR@@,${PKGMANDIR},'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
