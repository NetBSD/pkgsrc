# $NetBSD: Makefile,v 1.28 2020/01/26 17:32:03 rillig Exp $
#

DISTNAME=	fsh-1.2
PKGREVISION=	7
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/
MASTER_SITES+=	http://www.lysator.liu.se/fsh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lysator.liu.se/fsh/
COMMENT=	Fast remote command execution

GNU_CONFIGURE=	YES
INFO_FILES=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
