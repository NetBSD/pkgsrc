# $NetBSD: Makefile,v 1.5 2001/09/27 23:18:38 jlam Exp $
#

DISTNAME=	fsh-1.1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	fast remote command execution

DEPENDS+=	python-[0-9]*:../../lang/python

GNU_CONFIGURE=	YES
USE_GTEXINFO=	YES

.include "../../mk/bsd.pkg.mk"
