# $NetBSD: Makefile,v 1.24 2004/08/18 21:52:43 schmonz Exp $

DISTNAME=	getmail-4.0.11
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}old-versions/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.qcc.ca/~charlesc/software/getmail-4/
COMMENT=	Secure, flexible, reliable, easy-to-use fetchmail replacement

USE_BUILDLINK3=	yes

PYTHON_VERSIONS_ACCEPTED?=	23 23pth
PYTHON_PATCH_SCRIPTS=		*.py getmailcore/*.py
PYDISTUTILSPKG=			yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
