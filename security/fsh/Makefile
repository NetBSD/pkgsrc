# $NetBSD: Makefile,v 1.14 2005/03/20 12:51:54 fredb Exp $
#

DISTNAME=	fsh-1.2
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	Fast remote command execution

GNU_CONFIGURE=	YES
INFO_FILES=	fsh.info

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
