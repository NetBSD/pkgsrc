# $NetBSD: Makefile,v 1.53 2005/12/02 16:37:57 schmonz Exp $

DISTNAME=	getmail-4.4.3
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
