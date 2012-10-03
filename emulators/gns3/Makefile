# $NetBSD: Makefile,v 1.4 2012/10/03 12:55:13 asau Exp $

DISTNAME=	GNS3-0.7-src
PKGNAME=	gns3-0.7
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gns3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gns3.org/
COMMENT=	Graphical network simulator
LICENSE=	gnu-gpl-v2

DEPENDS+=	dynamips>=0.2.8rc1:../../emulators/dynamips

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
REPLACE_PYTHON+= src/GNS3/Dynagen/dynagen.py src/GNS3/Dynagen/confConsole.py
REPLACE_PYTHON+= src/GNS3/Dynagen/console.py src/GNS3/Dynagen/dynamips_lib.py
REPLACE_PYTHON+= src/GNS3/Dynagen/qemu_lib.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
