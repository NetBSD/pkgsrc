# $NetBSD: Makefile,v 1.16 2006/02/05 23:10:43 joerg Exp $
#

DISTNAME=	fsh-1.2
PKGREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	Fast remote command execution

GNU_CONFIGURE=	YES
INFO_FILES=	fsh.info

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
