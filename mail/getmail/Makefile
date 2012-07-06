# $NetBSD: Makefile,v 1.117 2012/07/06 15:05:24 schmonz Exp $

DISTNAME=		getmail-4.31.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/getmail/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none

PYTHON_PATCH_SCRIPTS=	*.py getmailcore/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
