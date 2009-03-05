# $NetBSD: Makefile,v 1.17 2009/03/05 18:51:29 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-readline-0
PKGREVISION=	3
CATEGORIES=	devel misc python

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/current/tut/node15.html
COMMENT=	Line editing support for Python

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/readline.c

USE_GNU_READLINE=	# defined

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= RLPREFIX=${BUILDLINK_PREFIX.readline}
PY_SETUP_SUBST+= RLRTPREFIX=${BUILDLINK_PREFIX.readline}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

BUILDLINK_API_DEPENDS.python23+=	python23>=2.3.5nb11
BUILDLINK_API_DEPENDS.python24+=	python24>=2.4.5nb1
BUILDLINK_API_DEPENDS.python25+=	python25>=2.5.2nb2

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
