# $NetBSD: Makefile,v 1.4 2006/02/05 23:08:31 joerg Exp $
#

DISTNAME=		gourmet-0.8.5.12
PKGREVISION=		2
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
