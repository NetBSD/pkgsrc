# $NetBSD: Makefile,v 1.9 2008/04/25 20:39:08 joerg Exp $
#

DISTNAME=		Pyro-3.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyro/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PLIST_SUBST+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"
MAKE_ENV+=		PKGSRC="1"
MAKE_ENV+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"

post-extract:
	set -e; \
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
