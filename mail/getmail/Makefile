# $NetBSD: Makefile,v 1.17 2004/08/02 16:24:30 schmonz Exp $

DISTNAME=	getmail-4.0.3
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE} ${HOMEPAGE}/old-versions/

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
