# $NetBSD: Makefile,v 1.9 2003/03/05 21:59:34 jschauma Exp $
#

DISTNAME=	fsh-1.2
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	fast remote command execution

GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

.include "../../lang/python/application.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
