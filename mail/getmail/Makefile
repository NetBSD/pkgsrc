# $NetBSD: Makefile,v 1.54 2006/01/03 16:46:48 schmonz Exp $

DISTNAME=	getmail-4.4.4
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}old-versions/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://pyropus.ca/software/getmail/
COMMENT=	Secure, flexible, reliable, easy-to-use fetchmail replacement

PYTHON_VERSIONS_ACCEPTED?=	24 23
PYTHON_PATCH_SCRIPTS=		*.py getmailcore/*.py
PYDISTUTILSPKG=			yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
