# $NetBSD: Makefile,v 1.10 2003/07/17 22:52:54 grant Exp $
#

DISTNAME=	fsh-1.2
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	fast remote command execution

GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

.include "../../lang/python/application.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
