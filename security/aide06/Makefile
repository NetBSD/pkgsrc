# $NetBSD: Makefile,v 1.5 2004/04/26 04:24:43 snj Exp $
#

DISTNAME=       aide-0.6
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Older intrusion detection system for checking file integrity

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=
USE_BUILDLINK3=	yes

.include "../../mk/bsd.pkg.mk"
