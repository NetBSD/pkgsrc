# $NetBSD: Makefile,v 1.33 2019/11/03 10:18:29 rillig Exp $

PKGNAME=	${PYPKGPREFIX}-readline-${PY_DISTVERSION}
CATEGORIES=	devel misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3/library/readline.html
COMMENT=	Line editing support for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/readline.c

USE_GCC_RUNTIME=	yes

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=		yes
PY_SETUP_SUBST+=	RLPREFIX=${BUILDLINK_PREFIX.readline}
PY_SETUP_SUBST+=	RLRTPREFIX=${BUILDLINK_PREFIX.readline}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
