# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 13:48:33 agc Exp $
#

DISTNAME=       aide-0.6
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	older intrusion detection system for checking file integrity

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=
USE_BUILDLINK2=	yes

.include "../../mk/bsd.pkg.mk"
