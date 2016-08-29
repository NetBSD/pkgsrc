# $NetBSD: Makefile,v 1.15 2016/08/29 15:50:06 wiz Exp $

DISTNAME=	logilab-common-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logilab-common/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-common
COMMENT=	Useful miscellaneous modules used by Logilab projects
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Cygwin" || ${OPSYS} == "Interix"
DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-extract:
	${MV} ${WRKSRC}/bin/pytest ${WRKSRC}/bin/pytest${PYVERSSUFFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pytest.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pytest${PYVERSSUFFIX}.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
