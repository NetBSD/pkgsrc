# $NetBSD: Makefile,v 1.13 2003/08/09 11:21:54 seb Exp $
#

DISTNAME=	fsh-1.2
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
