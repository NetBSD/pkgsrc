# $NetBSD: Makefile,v 1.3 2005/01/09 10:53:45 darcy Exp $
#

DISTNAME=		Pyro-3.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyro/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PLIST_SUBST+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"
MAKE_ENV+=			PKGSRC="1" PYVERSSUFFIX="-${PYVERSSUFFIX}"

post-extract:
	cd ${WRKSRC}/bin; \
	${MV} es es-${PYVERSSUFFIX}; \
	${MV} esd esd-${PYVERSSUFFIX}; \
	${MV} genguid genguid-${PYVERSSUFFIX}; \
	${MV} ns ns-${PYVERSSUFFIX}; \
	${MV} nsc nsc-${PYVERSSUFFIX}; \
	${MV} nsd nsd-${PYVERSSUFFIX}; \
	${MV} pyroc pyroc-${PYVERSSUFFIX}; \
	${MV} rns rns-${PYVERSSUFFIX}; \
	${MV} wxnsc wxnsc-${PYVERSSUFFIX}; \
	${MV} xnsc xnsc-${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
