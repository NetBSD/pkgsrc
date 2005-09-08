# $NetBSD: Makefile,v 1.2 2005/09/08 18:00:35 drochner Exp $
#

DISTNAME=		gourmet-0.8.5.12
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grecipe-manager/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://grecipe-manager.sourceforge.net/
COMMENT=		Recipe database

USE_PKGLOCALEDIR=	yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 23 24

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-metakit/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
