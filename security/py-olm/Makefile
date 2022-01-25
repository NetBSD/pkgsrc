# $NetBSD: Makefile,v 1.2 2022/01/25 13:12:49 wiz Exp $

DISTNAME=	olm-3.2.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	https://gitlab.matrix.org/matrix-org/olm/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.matrix.org/matrix-org/olm/
COMMENT=	Olm bindings for Python
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/python

DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py27"
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

.include "../../security/olm/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
