# $NetBSD: Makefile,v 1.91 2009/12/02 21:03:10 schmonz Exp $

DISTNAME=	getmail-4.15.0
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}old-versions/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://pyropus.ca/software/getmail/
COMMENT=	Secure, flexible, reliable, easy-to-use fetchmail replacement
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_PATCH_SCRIPTS=		*.py getmailcore/*.py
PYDISTUTILSPKG=			yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
