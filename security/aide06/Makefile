# $NetBSD: Makefile,v 1.5.2.1 2004/07/30 15:47:47 agc Exp $
#

DISTNAME=       aide-0.6
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Older intrusion detection system for checking file integrity

#BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	yacc lex

.include "../../mk/bsd.pkg.mk"
#don't set YACC so configure can correctly find bison
YACC=
