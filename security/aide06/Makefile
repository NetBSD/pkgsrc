# $NetBSD: Makefile,v 1.8 2005/04/11 21:47:10 tv Exp $
#

DISTNAME=       aide-0.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Older intrusion detection system for checking file integrity

#BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	yacc lex

.include "../../mk/bsd.pkg.mk"
#don't set YACC so configure can correctly find bison
YACC=
