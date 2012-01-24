# $NetBSD: Makefile,v 1.107 2012/01/24 12:01:13 obache Exp $

DISTNAME=	getmail-4.24.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}old-versions/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://pyropus.ca/software/getmail/
COMMENT=	Secure, flexible, reliable, easy-to-use fetchmail replacement
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_PATCH_SCRIPTS=	*.py getmailcore/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
