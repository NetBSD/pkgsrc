# $NetBSD: Makefile,v 1.4 2000/09/03 13:09:20 wiz Exp $
#

DISTNAME=       aide-0.6
CATEGORIES=	security
MASTER_SITES=   http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html

BUILD_DEPENDS+=	bison:../../devel/bison

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=

.include "../../mk/bsd.pkg.mk"
