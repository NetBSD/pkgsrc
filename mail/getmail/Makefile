# $NetBSD: Makefile,v 1.35 2004/12/20 04:12:47 schmonz Exp $

DISTNAME=	getmail-4.2.5
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}old-versions/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.qcc.ca/~charlesc/software/getmail-4/
COMMENT=	Secure, flexible, reliable, easy-to-use fetchmail replacement

USE_BUILDLINK3=	yes

PYTHON_VERSIONS_ACCEPTED?=	23 23pth 24 24pth
PYTHON_PATCH_SCRIPTS=		*.py getmailcore/*.py
PYDISTUTILSPKG=			yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
