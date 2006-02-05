# $NetBSD: Makefile,v 1.16 2006/02/05 23:08:36 joerg Exp $
#

DISTNAME=	sybase-0.36
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	http://object-craft.com.au/projects/sybase/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.object-craft.com.au/projects/sybase/
COMMENT=	Sybase interface for Python using FreeTDS

PYTHON_VERSIONS_ACCEPTED=	21 22 23 24

PYSETUPBUILDARGS=	build_ext -D HAVE_FREETDS=61 -U WANT_BULKCOPY
PYDISTUTILSPKG=		yes

SYBASE=		${BUILDLINK_PREFIX.freetds}
MAKE_ENV+=	SYBASE=${SYBASE:Q}

post-patch:
	${SED} "s|\(runtime_library_dirs = \)None|\1['${SYBASE}'+'/lib']|" \
		<${WRKSRC}/setup.py >${WRKSRC}/setup.py.tmp
	${MV} ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
