# $NetBSD: Makefile,v 1.1 2020/04/20 14:37:46 schmonz Exp $

GITHUB_PROJECT=	ApprovalTests.Python
GITHUB_TAG=	0.2.6
DISTNAME=	0.2.6
PKGNAME=	${PYPKGPREFIX}-approvaltests-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=approvals/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.5.27:../../x11/py-pyperclip

WRKSRC=		${WRKDIR}/ApprovalTests.Python-0.2.6
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
