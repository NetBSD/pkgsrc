# $NetBSD: Makefile,v 1.26 2017/01/19 18:52:23 agc Exp $
#

DISTNAME=	fsh-1.2
PKGREVISION=	6
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/
MASTER_SITES+=	http://www.lysator.liu.se/fsh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	Fast remote command execution

GNU_CONFIGURE=	YES
INFO_FILES=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
