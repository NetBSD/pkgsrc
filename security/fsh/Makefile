# $NetBSD: Makefile,v 1.23 2012/10/23 18:16:27 asau Exp $
#

DISTNAME=	fsh-1.2
PKGREVISION=	5
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	Fast remote command execution

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
