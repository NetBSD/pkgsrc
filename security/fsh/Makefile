# $NetBSD: Makefile,v 1.12 2003/08/04 22:55:22 seb Exp $
#

DISTNAME=	fsh-1.2
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	Fast remote command execution

GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	fsh.info

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
