# $NetBSD: Makefile,v 1.164 2019/02/07 22:23:12 schmonz Exp $

DISTNAME=		getmail-5.9
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/getmail/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

REPLACE_PYTHON=		*.py getmailcore/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 4.53.0

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
