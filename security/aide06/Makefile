# $NetBSD: Makefile,v 1.9 2005/05/15 19:05:54 jlam Exp $
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
USE_TOOLS+=	bison

.include "../../mk/bsd.pkg.mk"

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
#don't set YACC so configure can correctly find bison
YACC=
.endif
