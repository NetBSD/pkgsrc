# $NetBSD: Makefile,v 1.12 2003/07/21 17:20:04 martti Exp $
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

USE_BUILDLINK2= # defined

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=

.include "../../security/mhash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
