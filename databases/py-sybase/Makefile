# $NetBSD: Makefile,v 1.8 2005/01/23 20:41:45 recht Exp $
#

DISTNAME=	sybase-0.36
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://object-craft.com.au/projects/sybase/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.object-craft.com.au/projects/sybase/
COMMENT=	Sybase interface for Python using FreeTDS

PYTHON_VERSIONS_ACCEPTED=	21 22 23

BUILDLINK_DEPENDS.freetds=	freetds-0.61*
PYSETUPBUILDARGS=	build_ext -D HAVE_FREETDS=61 -U WANT_BULKCOPY
USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes

SYBASE=		${BUILDLINK_PREFIX.freetds}/freetds
MAKE_ENV+=	SYBASE=${SYBASE}

post-patch:
	${SED} "s|\(runtime_library_dirs = \)None|\1['${SYBASE}'+'/lib']|" \
		<${WRKSRC}/setup.py >${WRKSRC}/setup.py.tmp
	${MV} ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
