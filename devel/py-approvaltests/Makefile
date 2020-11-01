# $NetBSD: Makefile,v 1.2 2020/11/01 13:52:43 schmonz Exp $

GITHUB_PROJECT=	ApprovalTests.Python
GITHUB_TAG=	0.2.7
DISTNAME=	0.2.7
PKGNAME=	${PYPKGPREFIX}-approvaltests-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=approvals/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.5.27:../../x11/py-pyperclip

WRKSRC=		${WRKDIR}/ApprovalTests.Python-${GITHUB_TAG}
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
