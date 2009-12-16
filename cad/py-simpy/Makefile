# $NetBSD: Makefile,v 1.9 2009/12/16 17:53:50 drochner Exp $
#

DISTNAME=		SimPy-2.0.1
PKGNAME=		${PYPKGPREFIX}-simpy-2.0.1
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=simpy/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://simpy.sourceforge.net/
COMMENT=		Discrete event simulation framework

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} SimPy/testSimPy.py)

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
