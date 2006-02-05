# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:13 joerg Exp $

DISTNAME=	pyxmms-2.02
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://people.via.ecp.fr/~flo/2002/PyXMMS/dist/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.via.ecp.fr/~flo/index.en.xhtml\#PyXMMS_and_PyXMMS-remote
COMMENT=	Python interface to XMMS

PYDISTUTILSPKG=	yes
NO_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	setup.cfg
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX}/,g'

.include "../../audio/xmms/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
