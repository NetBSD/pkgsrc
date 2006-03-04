# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:27 jlam Exp $
#

DISTNAME=		Pyro-3.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyro/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python

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
