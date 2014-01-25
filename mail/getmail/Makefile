# $NetBSD: Makefile,v 1.138 2014/01/25 10:45:19 wiz Exp $

DISTNAME=		getmail-4.43.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/getmail/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

REPLACE_PYTHON=	*.py getmailcore/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 4.43.0

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
