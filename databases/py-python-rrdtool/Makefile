# $NetBSD: Makefile,v 1.2 2014/08/12 08:11:26 fhajny Exp $

DISTNAME=	python-rrdtool-1.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-rrdtool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pbanaszkiewicz/python-rrdtool
COMMENT=	Python bindings for RRDTool, the graphing and logging utility
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.4.7

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	rrdtool-1.4.7/src/librrd.pc.in

PYDISTUTILSPKG=		yes

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
