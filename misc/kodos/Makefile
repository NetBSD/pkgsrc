# $NetBSD: Makefile,v 1.1.1.1 2003/12/05 18:56:38 recht Exp $
#

DISTNAME=	kodos-2.0
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kodos/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://kodos.sourceforge.net/
COMMENT=	GUI for creating, testing and debugging Python REs

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-base/buildlink2.mk"
.include "../../x11/py-qt3-sip/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
