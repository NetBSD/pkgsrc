# $NetBSD: Makefile,v 1.6 2002/01/18 13:29:29 drochner Exp $
#

DISTNAME=	fsh-1.1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	fast remote command execution

GNU_CONFIGURE=	YES
USE_GTEXINFO=	YES

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

.include "../../lang/python/application.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
