# $NetBSD: Makefile,v 1.1 2015/08/22 14:47:55 bsiegert Exp $

GITHUB_PROJECT=	borg
DISTNAME=	0.24.0
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=borgbackup/}
DIST_SUBDIR=	${GITHUB_PROJECT}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=borgbackup/borg/}
COMMENT=	Deduplicating backup program with compression and encryption
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.4.6:../../devel/py-msgpack

PYTHON_VERSIONS_INCOMPATIBLE=	27
MAKE_ENV+=	BORG_OPENSSL_PREFIX=${SSLBASE:Q}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv borg borg${PYVERSSUFFIX}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
