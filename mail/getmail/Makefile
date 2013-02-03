# $NetBSD: Makefile,v 1.125 2013/02/03 14:36:45 schmonz Exp $

DISTNAME=		getmail-4.37.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}old-versions/
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/getmail/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

PYTHON_PATCH_SCRIPTS=	*.py getmailcore/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
