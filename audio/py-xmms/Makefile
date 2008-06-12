# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:15 joerg Exp $

DISTNAME=	pyxmms-2.02
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://people.via.ecp.fr/~flo/2002/PyXMMS/dist/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://people.via.ecp.fr/~flo/index.en.xhtml\#PyXMMS_and_PyXMMS-remote
COMMENT=	Python interface to XMMS

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
NO_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	setup.cfg
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX}/,g'

.include "../../audio/xmms/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
