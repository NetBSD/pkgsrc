# $NetBSD: Makefile,v 1.2 2000/04/26 12:51:35 hubertf Exp $
#

DISTNAME=       aide-0.6
CATEGORIES=	security
MASTER_SITES=   http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html

GNU_CONFIGURE=	yes
BUILD_DEFS+=	bison:../../devel/bison
CONFIGURE_ENV+=	YACC="bison -y"

.include "../../mk/bsd.pkg.mk"
