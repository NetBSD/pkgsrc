# $NetBSD: Makefile,v 1.163 2018/11/09 17:02:10 schmonz Exp $

DISTNAME=		getmail-5.8
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
