# $NetBSD: Makefile,v 1.1 2021/12/15 09:03:52 schmonz Exp $

VERSION=	0.0.3
GITHUB_TAG=	refs/tags/v${VERSION}
GITHUB_PROJECT=	EmptyFiles.Python
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-empty-files-${VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=approvals/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/approvals/${GITHUB_PROJECT}
COMMENT=	Null Object pattern for files
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	test
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
