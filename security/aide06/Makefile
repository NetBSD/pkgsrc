# $NetBSD: Makefile,v 1.3 2003/07/21 17:20:04 martti Exp $
#

DISTNAME=       aide-0.6
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Older intrusion detection system for checking file integrity

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=
USE_BUILDLINK2=	yes

.include "../../mk/bsd.pkg.mk"
