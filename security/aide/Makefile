# $NetBSD: Makefile,v 1.13 2004/04/25 02:59:29 snj Exp $
#

DISTNAME=       aide-0.9
CATEGORIES=	security
MASTER_SITES=   http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILDLINK_DEPENDS.mhash?=	mhash>=0.8.17

USE_BUILDLINK3= yes

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=

.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
