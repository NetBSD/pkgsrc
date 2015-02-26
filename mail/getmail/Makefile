# $NetBSD: Makefile,v 1.143 2015/02/26 04:08:25 schmonz Exp $

DISTNAME=		getmail-4.47.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/getmail/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

REPLACE_PYTHON=	*.py getmailcore/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 4.44.0

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
