# $NetBSD: Makefile,v 1.5 2001/02/17 17:49:39 wiz Exp $
#

DISTNAME=       aide-0.6
CATEGORIES=	security
MASTER_SITES=   http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	free intrusion detection system for checking file integrity

BUILD_DEPENDS+=	bison:../../devel/bison

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=

.include "../../mk/bsd.pkg.mk"
